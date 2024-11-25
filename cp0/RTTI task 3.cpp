#include <iostream>
using namespace std;

class Coke {
public:
    void drinkC() {
        cout << "Drinking Coke" << endl;
    }
};

class Sprite {
public:
    void drinkS() {
        cout << "Drinking Sprite" << endl;
    }
};

int main() {
    Coke myCoke;

   
    myCoke.drinkC();  

    
    Sprite* fakeSprite = reinterpret_cast<Sprite*>(&myCoke);

    
    fakeSprite->drinkS(); 

    return 0;
}
