#ifndef MECHANIC
#define MECHANIC

#include <iostream>
#include "person.h"
using namespace std;

class mechanic : public person {
private:
    int counter;
    int current;
public:
    mechanic();
    person::Appointment* Bookings;
    mechanic(string n, int id, int age, int c);
    bool isAvailable(Appointment time);
    void setCounter(int count);
    void setCurrent(int cu);
    int getCounter() const;
    void addBookingTime(person::Appointment app);
    Appointment* getBookedTimes() const;
    ~mechanic();
};

#endif