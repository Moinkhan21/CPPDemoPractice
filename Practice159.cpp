#include <iostream>
using namespace std;

class Maths {
    public:

    int sum(int a, int b) {
        cout << "I am in first singnature" << endl;
        return a + b;
    }
    int sum(int a, int b, int c) {
        cout << "I am in second singnature" << endl;
        return a + b + c;
    }
    int sum(int a, float b) {
        cout << "I am in third singnature" << endl;
        return a + b + 10;
    }
};

int main() {
    Maths obj;
    cout << obj.sum(1, 3) << endl;
    cout << obj.sum(1, 3, 5) << endl;
    cout << obj.sum(1, 3.5f) << endl;
    return 0;
}