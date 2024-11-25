#include <iostream>
#include <vector>
using namespace std;


class Animal {
public:
 
    virtual void makeSound() const {
        cout << "Some animal sound" << endl;
    }
    
  
    virtual ~Animal() {}
};


class Dog : public Animal {
public:
   
    void makeSound() const override {
        cout << "Woof! Woof!" << endl;
    }
};


class Cat : public Animal {
public:
 
    void makeSound() const override {
        cout << "Meow! Moow!" << endl;
    }
};

int main() {
    
    vector<Animal*> animals;
    
   
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    
  
    animals.push_back(dog);
    animals.push_back(cat);
    

    for (const auto& animal : animals) {
        animal->makeSound(); 
    }
    
   
    for (auto& animal : animals) {
        delete animal;
    }
    
    return 0;
}
