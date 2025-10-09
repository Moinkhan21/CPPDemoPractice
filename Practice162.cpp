#include <iostream>
using namespace std;

class Animal{
    public:
    virtual void speak() {
        cout << "Speaking... " << endl;
    }
};

class Dog: public Animal {
    public:
    //Override
    void speak() {
        cout << "Barking... " << endl;
    }
};

int main() {
    // Animal* a = new Animal();
    // a->speak();

    //Upcasting
    Animal* a = new Dog();
    a->speak();

    //Downcasting
    Dog* b = (Dog*)new Animal();
    b->speak();

    return 0;
}