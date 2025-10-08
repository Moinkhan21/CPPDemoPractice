#include <iostream>
using namespace std;

class Animal {
    private:
        int age;
        int weight;

    public:
        void eat() {
            cout << "Eating..." << endl;
        }
        int getAge() {
            return this-> age;
        }
        void setAge(int age) {
            this-> age = age;
        }
};

int main() {
    Animal a;
    a.setAge(10);
}