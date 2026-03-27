#include <iostream>
using namespace std;

// ======================================================================
// CLASS: Car (Base Class)
// ----------------------------------------------------------------------
// Represents a generic car with common properties and behaviors.
//
// DATA MEMBERS:
//   • name   → car name
//   • weight → weight of car
//   • age    → age of car
//
// FUNCTIONS:
//   • speedUp()  → increases speed
//   • breakMarro() → applies brake
// ======================================================================
class Car {
public:
    string name;
    int weight;
    int age;

    void speedUp() {
        cout << "Speeding up..." << endl;
    }

    void breakMarro() {
        cout << "Brake applied..." << endl;
    }
};

// ======================================================================
// CLASS: Scorpio (Derived Class)
// ----------------------------------------------------------------------
// Inherits properties and behaviors from Car.
//
// RELATION:
//   Scorpio IS-A Car
// ======================================================================
class Scorpio : public Car {

    // Inherits:
    // name, weight, age
    // speedUp(), breakMarro()
};

// ======================================================================
// MAIN FUNCTION
// ======================================================================
int main() {

    // Create object of derived class
    Scorpio babbarSherWali;

    // Access inherited members
    babbarSherWali.name = "Mahindra Scorpio";
    babbarSherWali.weight = 2000;
    babbarSherWali.age = 2;

    // Call inherited functions
    babbarSherWali.speedUp();
    babbarSherWali.breakMarro();

    return 0;
}