#include <iostream>
using namespace std;
 
class Animal {
    protected:
        int age;
};

class Dog:private Animal {
    public:
        void print() {
            cout << this->age << endl;
        }
};

int main() {
    Dog d1;
    cout << d1.age;
    return 0;
}