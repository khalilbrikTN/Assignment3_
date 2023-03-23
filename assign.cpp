#include <iostream>
#include <fstream>
#include <string>
#include "mechanic.h"
#include "customer.h"
#include "queue.h"

using namespace std;

int main()
{

    ifstream dataMechanic("dataMechanic.txt");
    string temp;  // will store the line from the text file
    string temp2; // will store the line from the text file
    getline(dataMechanic, temp);

    // the number of mechanics available
    int NumMechanics = stoi(temp);
    mechanic* Mechanics = new mechanic[NumMechanics];
    // filling the data about the mechanics
    for (int j = 0; j < NumMechanics; j++)
    {
        Mechanics[j] = mechanic("", 0, 0, 0);
        getline(dataMechanic, temp);
        Mechanics[j].setName(temp);
        getline(dataMechanic, temp);
        Mechanics[j].setID(stoi(temp));
        getline(dataMechanic, temp);
        Mechanics[j].setAge(stoi(temp));
        getline(dataMechanic, temp);
        Mechanics[j].setCounter(stoi(temp));
        // the reserved appoitments of mechanics
        for (int i = 0; i < Mechanics[j].getCounter(); i++)
        {
            getline(dataMechanic, temp);
            Mechanics[j].Bookings[i].hours = stoi(temp);
            getline(dataMechanic, temp);
            Mechanics[j].Bookings[i].mins = stoi(temp);
        }
    };

    ifstream dataCustomer("dataCustomer.txt");
    getline(dataCustomer, temp);
    int sizeCustomer = stoi(temp);
    customer* AllCustomers = new customer[sizeCustomer];

    queue<customer> Customers(sizeCustomer);
    bool check = false; // this to check whether the customer was assigned a mechanic or not
    for (int j = 0; j < sizeCustomer; j++)
    {
        getline(dataCustomer, temp); // temp stores the name
        AllCustomers[j].setName(temp);
        getline(dataCustomer, temp); // temp stores the age
        AllCustomers[j].setAge(stoi(temp));
        getline(dataCustomer, temp);  // get hours
        getline(dataCustomer, temp2); // get minutes
        AllCustomers[j].setAppointment(stoi(temp), stoi(temp2));

        // now we will check for the availability of mechanics
        // The first mechanic available will be assigned the customer
        check = false;
        for (int i = 0; i < NumMechanics; i++)
        {

            if (Mechanics[i].isAvailable(AllCustomers[j].getAppointment()))
            {
                Mechanics[i].addBookingTime(AllCustomers[j].getAppointment());
                AllCustomers[j].setMechanicID(Mechanics[i].getID());
                Customers.push(AllCustomers[j]);
                check = true;
                cout << "Mr." << AllCustomers[j].getName();
                cout << " should be assigned to " + Mechanics[i].getName() + " at " + to_string(AllCustomers[j].getAppointment().hours) + ":" + to_string(AllCustomers[j].getAppointment().mins) + "\n";
                break; // if one mechanic available found we break
            }
        }
        if (!check) // if no mechanic found we cancel
        {
            cout << "Sorry Mr." << AllCustomers[j].getName() << " you order is canceled because no mechanic is available!" << endl;
        }
        else
        {
        }
    };

    return 0;
};