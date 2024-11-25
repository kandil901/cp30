#include <iostream>
#include <exception>


class Dog {
public:
    virtual const char* what() const {
        return "Dog exception thrown!";
    }
};


class Puppy : public Dog {
public:
    const char* what() const override {
        return "Dog exception thrown!";
    }
};


void throwException(int input) {
    if (input == 1) {
        throw Dog();      
    }
    else if (input == 2) {
        throw Puppy();    
    }
    else {
        throw std::runtime_error("Other exception thrown!"); 
    }
}

int main() {
    for (int i = 1; i <= 3; ++i) {
        try {
            throwException(i);
        }
        catch (const Dog& d) {
            std::cout << d.what() << " - Caught in Dog catch block." << std::endl;
        }
        catch (const 
        Puppy& p) {
            std::cout << p.what() << " - Caught in Puppy catch block." << std::endl;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << " - Caught in std::exception catch block." << std::endl;
        }
    }

    return 0;
}