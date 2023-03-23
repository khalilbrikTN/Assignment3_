#include "mechanic.h"
#include <iostream>
using namespace std;

mechanic::mechanic() {

}

mechanic::mechanic(string n = "", int id = 0, int age = 0, int c = 0)
    :person(n, id, age)
{
    setCurrent(0);
    setCounter(c);
    Bookings = new person::Appointment[counter];

};

mechanic::~mechanic() {

}
bool mechanic::isAvailable(Appointment time) {
    for (int i = 0; i < counter; i++) {
        if (time.hours == Bookings[i].hours && time.mins == Bookings[i].mins) {
            return false;
        }
    }
    return true;
}
void mechanic::setCounter(int count) {
    counter = count;

};


int mechanic::getCounter() const {
    return counter;
}
void mechanic::addBookingTime(person::Appointment app) {

    Bookings[current] = app;
    current += 1;
    return;
}

void mechanic::setCurrent(int cu) {
    current = cu;
}

person::Appointment* mechanic::getBookedTimes() const {
    return Bookings;
}