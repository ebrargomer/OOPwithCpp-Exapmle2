
#ifndef _COURIER_H_
#define _COURIER_H_
#include <iostream>
#include <stdlib.h>
#include "Person.h"
using namespace std;

class Courier : public Person {
	private:
    string vehicle_type;
    int capacity;
public:
    Courier() {};
    ~Courier() {/*Courier list deleted in Business Dest*/}
    Courier(string new_name, string new_surname, string type) :Person(new_name, new_surname) {
        vehicle_type = type;
        if (vehicle_type == "bicycle") capacity = 10;
        else if (vehicle_type == "motorcycle") capacity = 35;
        else if (vehicle_type == "car") capacity = 200;
        else exit(-1);
    };
    bool operator==(Courier& incoming) {
        if (incoming.surname == this->surname && incoming.getCapacity(&incoming) == this->getCapacity(this))  return true;
        else return false;
    }
    string gettype(Courier*) { return vehicle_type; }
    int getCapacity(Courier*) { return capacity; }
};

#endif
