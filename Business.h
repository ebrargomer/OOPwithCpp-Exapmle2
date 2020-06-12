
#ifndef _BUSINESS_H_
#define _BUSINESS_H_
#include <iostream>
#include "Owner.h"
#include "Courier.h"

using namespace std;

class Business{ 
    private:
        string bus_name;
        string address;
    public:
    	static int corcount;
        Owner* owners;
        Courier* couriers;
        Business(string new_bus_name, string new_adress, Owner new_owners[], int new_ownership) :bus_name(new_bus_name), address(new_adress), owners(new_owners) {
            for (int i = 0; i < new_ownership; i++) owners[i].setOwner(new_ownership);
            couriers=NULL; 
        }
        void const list_owners();
        void const list_couriers();
        void hire_courier(Courier&);
        void fire_courier(Courier&);
        void const operator()();
        Courier const operator[](int); 
        int calculate_shipment_capacity();
        ~Business() {
            delete[] couriers;
            delete []owners;
        }
};

#endif
