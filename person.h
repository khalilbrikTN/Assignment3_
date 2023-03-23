#ifndef PERSON
#define PERSON
#include <iostream>
using namespace std;

class person {
private:
    string Name;
    int ID;
    int Age;
public:
    person(string n = "", int id = 0, int age = 0);
    void setName(string n);
    void setID(int id);
    void setAge(int age);
    string getName() const;
    int getID() const;
    int getAge() const;
    void printInfo() const;
    struct Appointment {
        int hours;
        int mins;
    };
    void setAppointment(int hours, int minutes);

};

#endif