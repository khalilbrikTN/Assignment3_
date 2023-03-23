#include <iostream>
#include "customer.h"
using namespace std;


void customer::setMechanicID(int id) {
    MechanicID = id;
}
void customer::setAppointment(int hour, int minutes) {
    app.hours = hour;
    app.mins = minutes;
}
int customer::getMechanicID() const {
    return MechanicID;
}
person::Appointment customer::getAppointment() const {
    return app;
};

bool customer:: operator>(const customer& customer2) const {
    if (this->getAppointment().hours > customer2.getAppointment().hours) {
        return true;
    }
    else if ((this->getAppointment().hours == customer2.getAppointment().hours) && (this->getAppointment().mins > customer2.getAppointment().mins)) {
        return true;
    }
    else {
        return false;
    }
}

bool customer :: operator<(const customer& customer2) const {
    if (this->getAppointment().hours < customer2.getAppointment().hours) {
        return true;
    }
    else if ((this->getAppointment().hours == customer2.getAppointment().hours) && (this->getAppointment().mins < customer2.getAppointment().mins)) {
        return true;
    }
    else {
        return false;
    }
}
bool customer :: operator==(const customer& customer2) const {
    if ((this->getAppointment().hours == customer2.getAppointment().hours) && (this->getAppointment().mins == customer2.getAppointment().mins)) {
        return true;
    }
    else {
        return false;
    }
}