#include <iostream>
using namespace std;

class Animal {

    private:
    int weight;
    public:
    //State & Properties
    int age;
    string type;

    //Default constructor
    Animal() {
        this->weight = 0;
        this->age = 0;
        this->type = "";
        cout << "Constructor called" << endl;
    }

    //Parameterized constructor
    Animal(int age){
        this->age = age;
        cout << "Parameterized constructor called" << endl;
    }

    Animal(int age, int weight){
        this->age = age;
        this->weight = weight;
        cout << "Parameterized constructor with 2 parameters called" << endl;
    }

    Animal(int age, int weight, string type){
        this->age = age;
        this->weight = weight;
        this->type = type;
        cout << "Parameterized constructor with 3 parameters called" << endl;
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

    Animal a(10);
    Animal* b = new Animal(100);
    Animal c(10, 20);
    Animal* d = new Animal(10, 20, "Dog");
    Animal e = Animal(10, 20, "Cat");

    
    return 0;
}