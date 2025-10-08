#include <iostream>
using namespace std;

class Car {
    public:
       string name;
       int weight;
       int age;

    void speedUp() {
        cout << "Speeding up..." << endl;
    }

    void breakMarro() {
        cout << "Break maardi..." << endl;
    }
};

class Scorpio: public Car {

    
};

int main() {
    Scorpio babbarSherWali;
    babbarSherWali.speedUp();
    return 0;
}