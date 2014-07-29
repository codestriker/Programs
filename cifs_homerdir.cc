//-----------------------------------------------------------------------------
//  Copyright (c) 2007-2010 NetApp, Inc.
//  All Rights Reserved
//
//  Filename:    cifs_homedir.cc
//
//  Summary:     Handles all CIFS Server related tables and associated operations.
//
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Includes
//-----------------------------------------------------------------------------
#include "cifs.h"
#include <smf/rdb/rdb_tran.h>
#include <ng_shared/util/mgmt_logger.h>
#include <message_catalogs/cifs_errors.h>
#include <rpc/rpc.h>
#include <message_catalogs/vserver_errors.h>
#include <dirent.h>

// ACL related and File Access Rights definitions (part of SMB request).

#include <tables/rbac.h>

#define CLUS_FS_PATH  "/clus/"

static mgmt_logger::logger* plogger = mgmt_logger::log_manager::get_logger( "tables::cifs" );

/**********************************************************************************
 *       Local stuff
 *********************************************************************************/

/*
 * This routine checks to see if the string contains valid dynamic patterns.
 * Right now the only valid ones are "%d", "%w", "%u" and "%%".
 * "%%" is the pattern to escape a single '%' character.
 */
static bool is_valid_dynamic_string(std::string &str)
{
    const char *c = str.c_str();

    for (; *c != '\0'; c++) {
        if (*c == '%') {
            c++; 	// skip '%'
            if ((*c != 'd') && (*c != 'w') && (*c != 'u') && (*c != '%')) {
                return false;
            }
        }
    }

    return true;
}

/*
 * This routine checks to see if the string contains only characters
 * allowd by Windows in a name.
 */
static bool is_valid_windows_name(std::string &str)
{
    const char *c = str.c_str();

    for (; *c != '\0'; c++) {
        if ((*c == '"') ||
       	    (*c == '*') ||
       	    (*c == ':') ||
       	    (*c == '<') ||
       	    (*c == '>') ||
       	    (*c == '?') ||
       	    (*c == '\\') ||
       	    (*c == '|')) {
	    return false;
        }
    }

    return true;
}


/*
 * This routine checks to see if the share name contains valid contents.
 * It checks to see if dynamic patterns are valid, and other characters
 * contains only characters allowed by Windows in a share name.
 */
static bool is_valid_share_name(std::string &name)
{
    bool is_valid = false;

    is_valid = is_valid_dynamic_string(name);
    if (is_valid) {
        is_valid = is_valid_windows_name(name);
    }

    return is_valid;
}

/*
 * This routine checks to see if the share pattern contains valid contents.
 * It checks to see if dynamic patterns are valid, and other characters
 * contains only characters allowed by Windows in a foler/file name.
 */
static bool is_valid_share_pattern(std::string &pattern)
{
    bool is_valid = false;

    is_valid = is_valid_dynamic_string(pattern);
    if (is_valid) {
        is_valid = is_valid_windows_name(pattern);
    }

    return is_valid;
}

/* 
 * Put something here
 *//*
static bool is_valid_search_path(std::string path)
{
   string path;
   string vserver;
   DIR * dirp = NULL;
   if (get_vserver().get_id() == vserverid::CSERVER_ID) {
     
     refp< vserver_iterator > vs_itr = new vserver_iterator( NULL );
     vs_itr->set_vserver(get_vserver());
 
     if (!vs_itr->get()) {
     	return smdb_error::AppError(VSERVER_VSERVER_DOES_NOT_EXIST, toString_vserver());
     }
 
     vserver = vs_itr->toString_vserver();
 
     path = CLUS_FS_PATH + vserver + get_path();
     dirp = opendir(path.c_str());
 
      if (dirp == NULL) {
     	        return smdb_error::AppError(CIFS_ERROR_CIFS_INVALID_SHARE_PATH, get_path());
      }
 
     if (dirp != NULL) {
         (void) closedir(dirp);
     }       
}*/
/**********************************************************************************
 *       HomeDir stuff
 *********************************************************************************/

uint32_t cifs_homedir_searchpath_iterator::max_position()
{
    uint32_t max_position = 0;

    // find max position
    refp<cifs_homedir_searchpath_db_iterator> homedir_db_itr(new cifs_homedir_searchpath_db_iterator(NULL));
    homedir_db_itr->query_vserver(get_vserver());
    while (homedir_db_itr->next()) {
        if (max_position < homedir_db_itr->get_position()) {
            max_position = homedir_db_itr->get_position();
        }
    }

    return max_position;
}

bool cifs_homedir_searchpath_iterator::pathExists()
{
    // find max position
    refp<cifs_homedir_searchpath_db_iterator> homedir_db_itr(new cifs_homedir_searchpath_db_iterator(NULL));
    homedir_db_itr->query_vserver(get_vserver());
    while (homedir_db_itr->next()) {
        if (get_path().compare(homedir_db_itr->get_path().c_str()) == 0) {
            return true;
        }
    }

    return false;
}

smdb_error cifs_homedir_searchpath_iterator::move_up(const uint32_t& start_pos, const uint32_t& end_pos)
{
    smdb_error err = smdb_error::Ok;
    uint32_t i;

    /* Now that we could have holes, check to see if target is a hole.  If
       so, no need to move.
     */
    refp<cifs_homedir_searchpath_db_iterator> target_itr(new cifs_homedir_searchpath_db_iterator( NULL ));
    target_itr->query_vserver(get_vserver());
    target_itr->query_position(end_pos);
    if (!target_itr->next()) {
        return smdb_error::Ok;
    }

    for (i = start_pos; i <= end_pos; i++) {
        refp<cifs_homedir_searchpath_db_iterator> itr(new cifs_homedir_searchpath_db_iterator( NULL ));

        itr->query_vserver(get_vserver());
        itr->query_position(i);
        if (!itr->next()) {
	    // This is a hole.  Skip.
            continue;
        }

        if (!itr->remove()) {
            plogger->err("searchpath_iterator::move_up: failed to remove during shifting of search paths");
            return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_REMOVE_PATH,
					itr->get_path().c_str(),
					itr->getError().text());
        }

        itr->set_position(i-1);
        if (!itr->create()) {
            plogger->err("searchpath_iterator::move_up: failed to create during shifting of search paths");
            return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_CREATE_PATH,
					itr->get_path().c_str(),
					itr->getError().text());
        }
    };

    return smdb_error::Ok;
}

smdb_error cifs_homedir_searchpath_iterator::move_down(const uint32_t& start_pos, const uint32_t& end_pos)
{
    smdb_error err = smdb_error::Ok;
    uint32_t i;

    /* Now that we could have holes, check to see if target is a hole.  If
       so, no need to move.
     */
    refp<cifs_homedir_searchpath_db_iterator> target_itr(new cifs_homedir_searchpath_db_iterator( NULL ));
    target_itr->query_vserver(get_vserver());
    target_itr->query_position(start_pos);
    if (!target_itr->next()) {
        return smdb_error::Ok;
    }

    for (i = end_pos; i >= start_pos; i--) {
        refp<cifs_homedir_searchpath_db_iterator> itr(new cifs_homedir_searchpath_db_iterator( NULL ));

        itr->query_vserver(get_vserver());
        itr->query_position(i);
        if (!itr->next()) {
	    // This is a hole.  Skip.
            continue;
        }

        if (!itr->remove()) {
            plogger->err("searchpath_iterator::move_down: failed to remove during shifting of search paths");
            return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_REMOVE_PATH,
					itr->get_path().c_str(),
					itr->getError().text());
        }

        itr->set_position(i+1);
        if (!itr->create()) {
            plogger->err("searchpath_iterator::move_down: failed to create during shifting of search paths");
            return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_CREATE_PATH,
					itr->get_path().c_str(),
					itr->getError().text());
        }
    };

    return smdb_error::Ok;
}

uint32_t cifs_homedir_sharepattern_iterator::max_position()
{
    uint32_t max_position = 0;

    // find max position
    refp<cifs_homedir_sharepattern_db_iterator> homedir_db_itr(new cifs_homedir_sharepattern_db_iterator(NULL));
    homedir_db_itr->query_vserver(get_vserver());
    while (homedir_db_itr->next()) {
        if (max_position < homedir_db_itr->get_position()) {
            max_position = homedir_db_itr->get_position();
        }
    }

    return max_position;
}


has_choices
cifs_homedir_searchpath_iterator::haveChoices_vserver(const std::string& hint,
						      std::vector<std::string>& choices,
						      std::vector<std::string>& descriptions,
						      smdb_type::op op ) const
{
    choices.clear();
    descriptions.clear();

    std::set< std::string > vserver_names;
    refp< cifs_server_db_v2_iterator > cifs_server_itr(new cifs_server_db_v2_iterator( NULL ));
    // pick the vserver context from the smf_env and apply it over the underlying
    // iterator, as the iterator from which we are fetching the information is not
    // keyed on the vserver name.
    rbac_util::applyVserverQueryFromEnv(cifs_server_itr, *this);

    while (cifs_server_itr->next()) {
        vserver_names.insert( cifs_server_itr->toString_vserver() );
    }

    std::copy( vserver_names.begin(), vserver_names.end(), std::back_inserter(choices) );
    std::copy( vserver_names.begin(), vserver_names.end(), std::back_inserter(descriptions) );

    return has_choices::these;
}

smdb_error cifs_homedir_searchpath_iterator::get_imp()
{
    refp<cifs_homedir_searchpath_db_iterator> itr(new cifs_homedir_searchpath_db_iterator( NULL ));

    itr->set_vserver(get_vserver());
    itr->set_position(get_position());
    itr->set_path(get_path());
    if (!itr->get()) {
        return itr->getError();
    }

    set_vserver(itr->get_vserver());
    set_position(itr->get_position());
    set_path(itr->get_path());

    return smdb_error::Ok;
}

smdb_error cifs_homedir_searchpath_iterator::next_imp()
{
    refp<cifs_homedir_searchpath_db_iterator> itr(new cifs_homedir_searchpath_db_iterator( NULL ));

    itr->set_vserver(get_vserver());
    if (!have_position()) {
        set_position(0);
    }
    itr->set_position(get_position());
    itr->set_path(get_path());
    if (!itr->next()) {
        return itr->getError();
    }

    set_vserver(itr->get_vserver());
    set_position(itr->get_position());
    set_path(itr->get_path());

    return smdb_error::Ok;
}

smdb_error cifs_homedir_searchpath_iterator::remove_imp()
{
    smdb_error err = smdb_error::Ok;
    refp<cifs_homedir_searchpath_db_iterator> db_itr(new cifs_homedir_searchpath_db_iterator( NULL ));

    db_itr->query_vserver(get_vserver());
    db_itr->query_path(get_path());
    if (!db_itr->next()) {
	return smdb_error::KeyNotFound;
    }

    // remove the SMF
    if (!db_itr->remove()) {
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_REMOVE_PATH,
				    db_itr->get_path().c_str(),
				    db_itr->getError().text());
    }

    // Display warning message if user removes all the search for corresponding vserver.
    db_itr->clearQuery();
    db_itr->clearAllKeys();
    db_itr->query_vserver(get_vserver());
    if (!db_itr->next()) {
        std::string msg = message_catalog::get_message(CIFS_ERROR_HOMEDIR_ALL_SEARCH_PATH_REMOVAL_WARNING);
        message_log(LOG_WARNING, msg.c_str());
    }

    return err;
}

smdb_error cifs_homedir_searchpath_iterator::create_imp()
{
    smdb_error result = smdb_error::Ok;
    uint32_t max_pos = max_position();
    string path;
    string vserver;
    DIR * dirp = NULL;

    refp <cifs_server_db_v2_iterator> server_itr(new cifs_server_db_v2_iterator(NULL));
    server_itr->set_vserver(get_vserver());
    if (!server_itr->get()) {
        plogger->err("Failed to find vserver '%s' when adding search path", get_vserver().get_name().c_str());
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_CREATE_PATH,
				    get_path().c_str(),
				    "Invalid vserver");
    }

    // check for duplicates first
    refp<cifs_homedir_searchpath_db_iterator> dup_itr(new cifs_homedir_searchpath_db_iterator(NULL));
    dup_itr->query_vserver(get_vserver());
    dup_itr->query_path(get_path());
    if (dup_itr->next()) {
	return smdb_error::DuplicateKey;
    }

    // Make sure path starts with at least a "/"
    if (strncmp(get_path().c_str(), "/", 1) != 0)
    {
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_CREATE_PATH,
				    get_path().c_str(),
				    "Path needs to start with a '/'");
    }

    //Check if share path is valid
    //refp< vserver_iterator > vs_itr = new vserver_iterator( NULL );
    refp<vserver_iterator> vs_itr(new vserver_iterator(0));
    vs_itr->set_vserver(get_vserver());
 
    if (!vs_itr->get()) {
     	return smdb_error::AppError(VSERVER_VSERVER_DOES_NOT_EXIST, toString_vserver());
    }
 
    vserver = vs_itr->toString_vserver();
    path = CLUS_FS_PATH + vserver + get_path();
    dirp = opendir(path.c_str());
    if (dirp == NULL) {
        return smdb_error::AppError(CIFS_ERROR_CIFS_INVALID_SHARE_PATH, get_path());
   	}
    if (dirp != NULL) {
        (void) closedir(dirp);
    }
    // Needs to be filled . What error message ?
  /*  if (!is_valid_search_path(get_path())) {
     	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_CREATE_PATTERN,
     				    get_path().c_str(), " Search path is invalid.");
    }*/
    refp<cifs_homedir_searchpath_db_iterator> new_db_itr(new cifs_homedir_searchpath_db_iterator(NULL));
    new_db_itr->set_vserver(get_vserver());
    new_db_itr->set_path(get_path());
    new_db_itr->set_position(max_pos+1);

    // add to the RDB
    if (!new_db_itr->create()) {
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_CREATE_PATH,
				    new_db_itr->get_path().c_str(),
				    new_db_itr->getError().text());
    }

    return result;
}

smdb_error cifs_homedir_searchpath_iterator::add_imp()
{
    return create_imp();
}

smdb_error cifs_homedir_searchpath_iterator::myremove_imp()
{
    return remove_imp();
}

smdb_error
cifs_homedir_searchpath_iterator::move_imp( const smdb_type_unsigned& pos )
{
    uint32_t max_pos = max_position();
    smdb_type_text to_path;
    uint32_t current_pos;

    rdb_tran txn("cifs homedir searchpath move");
    smdb_error err = txn.create();
    if (err != smdb_error::Ok) {
	return err;
    }

    err = smdb_error::Ok;

    // lookup current
    refp< cifs_homedir_searchpath_db_iterator > cur_itr(new cifs_homedir_searchpath_db_iterator( NULL ));
    cur_itr->query_vserver(get_vserver());
    cur_itr->query_path(get_path());
    if (!cur_itr->next()) {
	txn.abort();
	return smdb_error::KeyNotFound;
    }
    current_pos = cur_itr->get_position();
    if (current_pos == pos) {
	// no move
	return smdb_error::Ok;
    }

    if (pos == 0) {
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_MODIFY_PATH,
				    get_path().c_str(),
				    "Can't move to position 0");
    }
    if (pos > max_pos) {
	char err_msg[256];
	snprintf(err_msg, sizeof(err_msg), "Can't move beyond max position %d", max_pos);
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_MODIFY_PATH,
				    get_path().c_str(),
				    err_msg);
    }

    refp< cifs_homedir_searchpath_db_iterator > db_itr(new cifs_homedir_searchpath_db_iterator( NULL ));

    db_itr->set_vserver(get_vserver());
    db_itr->set_position(current_pos);
    db_itr->set_path(get_path());
    if (!db_itr->get())
        {
            txn.abort();
            return smdb_error::KeyNotFound;
        }
    db_itr->remove();
    if ((err = db_itr->getError()) != smdb_error::Ok) {
	txn.abort();
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_REMOVE_PATH, db_itr->get_path().c_str(), err.text() );
    }

    uint32_t new_pos;
    if (pos > max_pos) {
	new_pos = max_pos;
    } else {
	new_pos = pos;
    }

    if (current_pos < new_pos) {
	// now move up the other entries until to-position
	if ((err = move_up(current_pos+1, new_pos)) != smdb_error::Ok) {
	    txn.abort();
	    return err;
	}
    } else {
	// now move down the other entries from to-position
	if ((err = move_down(new_pos, current_pos-1)) != smdb_error::Ok) {
	    txn.abort();
	    return err;
	}
    }

    db_itr->set_position(new_pos);
    db_itr->create();
    if ((err = db_itr->getError()) != smdb_error::Ok) {
	txn.abort();
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_CREATE_PATH, db_itr->get_path().c_str(), err.text() );
    }

    if ((err = txn.commit()) != smdb_error::Ok) {
	return err;
    }

    return smdb_error::Ok;
}

smdb_error cifs_homedir_sharepattern_iterator::remove_imp()
{
    smdb_error result = smdb_error::Ok;
    uint32_t current_position;

    refp<cifs_homedir_sharepattern_db_iterator> db_itr(new cifs_homedir_sharepattern_db_iterator( NULL ));

    db_itr->query_vserver(get_vserver());
    db_itr->query_share(get_share());
    if (!db_itr->next()) {
	return smdb_error::KeyNotFound;
    }

    current_position = db_itr->get_position();

    rdb_tran txn("cifs homedir sharepattern delete");
    smdb_error err = txn.create();
    if (err != smdb_error::Ok) {
	return err;
    }

    // remove the SMF
    if (!db_itr->remove()) {
	txn.abort();
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_REMOVE_PATTERN,
				    db_itr->get_share().c_str(),
				    db_itr->getError().text());
    }

    if ((err = txn.commit()) != Ok) {
	return smdb_error::StorageFailure;
    }

    return result;
}


smdb_error cifs_homedir_sharepattern_iterator::create_imp()
{
    smdb_error result = smdb_error::Ok;
    uint32_t max_pos = max_position();

    refp <cifs_server_db_v2_iterator> server_itr(new cifs_server_db_v2_iterator(NULL));
    server_itr->set_vserver(get_vserver());
    if (!server_itr->get()) {
        plogger->err("Failed to find vserver '%s' when adding share pattern", get_vserver().get_name().c_str());
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_CREATE_PATTERN,
				    get_share().c_str(),
				    get_pattern().c_str(),
				    "Invalid vserver");
    }

    if (!is_valid_share_name(get_share())) {
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_CREATE_PATTERN,
				    get_share().c_str(),
				    get_pattern().c_str(),
				    "Share name is not in valid format.");
    }
    if (!is_valid_share_pattern(get_pattern())) {
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_CREATE_PATTERN,
				    get_share().c_str(),
				    get_pattern().c_str(),
				    "Share path is not in valid format.");
    }

    refp<cifs_homedir_sharepattern_db_iterator> new_db_itr(new cifs_homedir_sharepattern_db_iterator(NULL));
    new_db_itr->set_vserver(get_vserver());
    new_db_itr->set_position(max_pos+1);
    new_db_itr->set_share(get_share());
    new_db_itr->set_pattern(get_pattern());

    rdb_tran txn("cifs homedir sharepattern create");
    smdb_error err = txn.create();
    if (err != smdb_error::Ok) {
	return err;
    }

    // add to the RDB
    if (!new_db_itr->create()) {
	txn.abort();
	return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_CREATE_PATTERN,
				    new_db_itr->get_share().c_str(),
				    new_db_itr->get_pattern().c_str(),
				    new_db_itr->getError().text());
    }

    if ((err = txn.commit()) != Ok) {
	return smdb_error::StorageFailure;
    }
    return result;
}


/*
 * NOTE: Only the pattern can be modified. All other fields are constants
 */
smdb_error cifs_homedir_sharepattern_iterator::modify_imp()
{
    smdb_error result = smdb_error::Ok;

    if (!is_valid_share_pattern(get_pattern())) {
        return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_MODIFY_PATTERN,
                                    get_share().c_str(),
                                    get_pattern().c_str(),
                                    "Share path is not in valid format.");
    }

    refp<cifs_homedir_sharepattern_db_iterator> db_itr(new cifs_homedir_sharepattern_db_iterator( NULL ));

    db_itr->query_vserver(get_vserver());
    db_itr->query_share(get_share());
    if (!db_itr->next()) {
        return smdb_error::KeyNotFound;
    }

    db_itr->set_pattern(get_pattern());

    rdb_tran txn("cifs homedir sharepattern modify");
    smdb_error err = txn.create();
    if (err != smdb_error::Ok) {
        return err;
    }

    // modify the SMF
    if (!db_itr->modify()) {
        txn.abort();
        return smdb_error::AppError(CIFS_ERROR_HOMEDIR_CANT_MODIFY,
                                    get_vserver().get_name().c_str(),
                                    db_itr->getError().text());
    }
    if ((err = txn.commit()) != Ok) {
        return smdb_error::StorageFailure;
    }

    return result;
}
