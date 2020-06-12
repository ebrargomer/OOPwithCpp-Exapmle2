#ifndef _OWNER_H_
#define _OWNER_H_

#include <iostream>
#include "Person.h"
using namespace std;
class Owner : public Person {
	private :
	int ownership;
	public:
    Owner(string newname, string newsurname) :Person(newname, newsurname) { ownership = 0; };
    Owner() {};
    ~Owner() {/*Owner list deleted in Business Dest*/ }
    void setOwner(int new_ownership) { ownership = 100 / new_ownership; }; 
	int getOwnership(Owner &incoming){ return ownership;}
    
};
#endif 
