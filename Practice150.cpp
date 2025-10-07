#include <iostream>
using namespace std;

class Animal {

    private:
    int weight;
    public:
    //State & Properties
    int age;
    string type;

    Animal() {
        this->weight = 0;
        this->age = 0;
        this->type = "";
        cout << "Constructor called" << endl;
    }

    //Behaviour & Functions
    void eat() {
        cout << "Eating..." << endl;
    }
    void sleep() {
        cout << "Sleeping..." << endl;
    }

    int getWeight() {
        return weight;
    }
    void setWeight(int w) {
        weight = w;
        //this->weight = weight; //when parameter name and class member name is same
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

    //To private member
    ramesh.setWeight(100);
    cout << "Weight of ramesh is: " << ramesh.getWeight() << endl;

    //Dynamic Object
    Animal *suresh = new Animal;
    (*suresh).age = 15;
    (*suresh).type = "Elephant";

    //Alternate way to access members using pointer
    suresh->age = 15;
    suresh->type = "Elephant";

    cout << "Age of suresh is: " << (*suresh).age << endl;
    cout << "Name of suresh is: " << suresh->type << endl;
    suresh->eat();
    suresh->sleep();
    
    return 0;
}