#include <iostream>
using namespace std;

class Animal {

    public:
    int age;
    int weight;

    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog: public Animal {

};

class Cat: protected Animal {
    public:
    void print(){
        cout << this->age << " " << this -> weight << endl;
    }
};

class Chimpanzee: private Animal {
    public:
    void print() {
        cout << this->age << " " << this->weight << endl;
    }
};

int main() {
    Dog d1;
    d1.eat();
   

    Cat c1;
    c1.print();

    Chimpanzee ch1;
    ch1.print();

    return 0;
}