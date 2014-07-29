#include<iostream.h>

using namespace std; 
class Planets {
 public:
   virtual void Water() = 0;
   virtual void Air() = 0;
 }; 
 class Earth : public virtual Planets {
 public:
	 virtual void Air() {
   cout << "Earth has air!";
  }
 };  

class Mars : public virtual Planets {
 public:
	 virtual void Water() {
	   cout << "Mars has water!";
   }
 }; 
 class EarthVisitsMars : public Earth, public Mars { }; 
 int main() {
	 Mars *pm= new EarthVisitsMars;
	 pm->Air(); //how??
	 pm->Water();   
	 getchar();
   return 0;
 } 
