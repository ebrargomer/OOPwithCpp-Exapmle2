#include "Business.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
int Business::corcount = 0;
const void Business::list_owners() {
	int k= owners[0].getOwnership(owners[0]);
    for (int i = 0; i < 100/k; i++) {
        cout << owners[i].name << " " << owners[i].surname << " " << owners[i].getOwnership(owners[i]) << endl;
    }
}

void Business::hire_courier(Courier& incoming) {
	if(couriers==NULL) {
		couriers = new Courier[1];
		couriers[0]=incoming;
		corcount++;
		return;
	}
	int i;
	Courier *temp=new Courier[corcount];
	for(i=0;i<corcount;i++)	temp[i]=couriers[i];
	delete [] couriers;
	couriers = new Courier[corcount+1];
	for(i=0;i<corcount;i++)	couriers[i]=temp[i];
	couriers[i]=incoming;
	delete [] temp;
	corcount++;
	return;
}

void const  Business::operator()(){
    cout << this->bus_name << " " << this->address << endl;
    this->list_owners();
    this->list_couriers();
 }

const void Business::list_couriers() {
	if(corcount==0) exit(-1);
	int i=0;
    while (i<corcount) {
        cout << couriers[i].name << " " << couriers[i].surname << " " << couriers[i].gettype(&couriers[i]) << endl;
        i++;
    }
}

const Courier Business::operator[](int index) {
    return couriers[index];
}

void Business::fire_courier(Courier& incoming) {
	if(corcount==0) exit(-1);
    int i = 0;
    while (!(couriers[i] == incoming)) i++;
    while(i<corcount-1){
       	couriers[i]=couriers[i+1];
		i++;
	}
	corcount--;
	
}

int Business::calculate_shipment_capacity() {
    int total = 0;
    for(int i=0;i<corcount;i++)
    {
        total += couriers[i].getCapacity(&couriers[i]);
    }
    return total;
}
