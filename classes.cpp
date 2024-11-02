#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Car {
public:
    string model;

};

class License {
public:
    string licNumber;
};

class Citizen {
protected:
    string name;
    int ID;
};
// Inheritance 
class Driver : public Citizen 
{
public:
    Driver(){}
    Driver(string name, int ID)
    {
        this->name = name;
        this->ID = ID;
    }

    License license; // Composition 
    void drive(Car car) // Association 
    {
        cout << name << " With ID: " << ID << " is driving " << car.model << endl;
    }
};

class Company {
public:
    string companyName;
    vector<Car*> carsOwned; // Aggregation

    void addCar(Car* car) { carsOwned.push_back(car); }

    void printCars()
    {
        cout << companyName << " owns:\n";
        for (const auto& car : carsOwned) {
            cout << car->model;
        }
    }
};

