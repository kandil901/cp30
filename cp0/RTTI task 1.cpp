#include <iostream>
using namespace std;


class Vehicle {
public:
    virtual void drive() {
        cout << "Driving a vehicle." << endl;
    }
    virtual ~Vehicle() {} 
};


class Car : public Vehicle {
public:
    void drive() override {
        cout << "Driving a car." << endl;
    }

    void fuel() {
        cout << "Car is fueled up ." << endl;
    }
};


class Bicycle : public Vehicle {
public:
    void drive() override {
        cout << "Riding a Bicycle." << endl;
    }
};


void TestVehicle(Vehicle* v) {
    if (Car* car = dynamic_cast<Car*>(v)) {
        car->drive();
        car->fuel();
    } else if (Bicycle* bicycle = dynamic_cast<Bicycle*>(v)) {
        bicycle->drive();
    } else {
        cout << "Unknown vehicle type." << endl;
    }
}

int main() {
    Vehicle* myCar = new Car();
    Vehicle* myBike = new Bicycle();

    TestVehicle(myCar);  
    TestVehicle(myBike); 

    delete myCar;
    delete myBike;

    return 0;
}

