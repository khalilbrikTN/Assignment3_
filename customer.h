#include <iostream>
#include "person.h"
using namespace std;

class customer : public person {
private:
    int MechanicID;
    person::Appointment app;

public:
    void setMechanicID(int id);
    void setAppointment(int hour, int minutes);
    int getMechanicID() const;
    person::Appointment getAppointment() const;
    bool operator>(const customer& customer2) const;
    bool operator<(const customer& customer2) const;
    bool operator==(const customer& customer2) const;
};