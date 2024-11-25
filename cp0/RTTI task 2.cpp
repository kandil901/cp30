#include <iostream>
using namespace std;

class Vehicle {
public:
    virtual void drive() {
        cout << "Driving a vehicle." << endl;
    }
    
    virtual void fuel() {
        cout << "Fueling is impossible for this vehicle type." << endl;
    }
};

class Car : public Vehicle {
public:
    void drive() override {
        cout << "Driving a blue car." << endl;
    }

    void fuel() override {
        cout << "Car is fueled up with diesel." << endl;
    }
};

class Bicycle : public Vehicle {
public:
    void drive() override {
        cout << "Riding a bicycle." << endl;
    }
};

void Fuel(Vehicle* v) {
    v->fuel();
}

int main() {
    Vehicle* myCar = new Car();
    Vehicle* myBike = new Bicycle();

    Fuel(myCar);   
    Fuel(myBike);  

    delete myCar;
    delete myBike;

    return 0;
}
