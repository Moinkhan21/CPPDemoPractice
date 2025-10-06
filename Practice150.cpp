#include <iostream>
using namespace std;

class Animal {

    public:
    //State & Properties
    int age;
    string type;

    //Behaviour & Functions
    void eat() {
        cout << "Eating..." << endl;
    }
    void sleep() {
        cout << "Sleeping..." << endl;
    }

};

int main() {
    cout << "Size of Empty class is: " << sizeof(Animal) << endl;

    Animal ramesh;
    ramesh.age = 10; // Error: 'int Animal::age' is private within this context
    ramesh.type = "Lion";
    cout << "Age of ramesh is: " << ramesh.age << endl;
    cout << "Name of ramesh is: " << ramesh.type << endl;

    ramesh.eat(); // Error: 'void Animal::eat()' is private within this context
    ramesh.sleep();
    return 0;
}