#include <iostream>
using namespace std;

class abc
{
    int x;
    int *y;

public:

    //ctor : old style
    // abc(int _x, int _y, int _z = 0){
    //     x = _x;
    //     y = new int (_y);
    //     z = _z;
    // }

    // Initialization list
    abc(int _x, int _y, int _z = 0) : x(_x), y(new int(_y)), z(_z) {}
    
    abc() {
        x = 0;
        y = new int(0);
    }

    int getX() const {
        return x;
    }

    void setX(int _val){
        x = _val;
    }

    int getY() const {
        return *y;
    }

    void setY(int _val)
    {
        *y = _val;
    }

    int getZ() const{
        return z;
    }
};

void printABC(const abc &a){
    cout << a.getX() << " " << a.getY() << a.getZ() << endl;
}

int main() {
    abc a;

    cout << a.getX() << endl;
    cout << a.getY() << endl;
    return 0;
}

int main2() {
    const int x = 5;
    abc a(1, 2, 3);
    printABC(a);
    return 0;
}