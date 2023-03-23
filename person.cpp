#include <iostream>
#include "person.h"
using namespace std;

person::person(string n, int id, int age) {
    setName(n);
    setID(id);
    setAge(age);
};

void person::setName(string n) {
    Name = n;
}
void person::setID(int id) {
    ID = id;
}
void person::setAge(int age) {
    Age = age;
}
string person::getName() const {
    return Name;
}
int person::getID() const {
    return ID;
}
int person::getAge() const {
    return Age;
}

void person::setAppointment(int hours, int minutes) {

};

void person::printInfo() const {
    cout << "Name :" << getName() << endl;
    cout << "ID :" << getID() << endl;
    cout << "Age :" << getAge() << endl;
}