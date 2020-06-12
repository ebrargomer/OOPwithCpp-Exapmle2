#ifndef _PERSON_H_
#define _PERSON_H_


#include <iostream>
using namespace std;
class Person {
public:
    string name;
    string surname;
    Person() {};
    Person(string newname, string newsurname) :name(newname), surname(newsurname) {};
    ~Person() { /*strings are allocated and reallocated automatically*/ }
};
#endif // !PERSON_H
