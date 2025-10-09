#include <iostream>
using namespace std;

class Animal{
    public:
    Animal() {
        cout << "I am inside animal constructor" << endl;
    }
    virtual void speak() {
        cout << "Speaking... " << endl;
    }
};

class Dog: public Animal {
    public:
    Dog() {
        cout << "I am inside dog constructor" << endl;
    }
    //Override
    void speak() {
        cout << "Barking... " << endl;
    }
};

int main() {

    Animal* a = new Animal();

    Dog* b = new Dog();

    return 0;
}