#include <iostream>
using namespace std;

class abc
{
    public:
        int x;
        int *y;

        abc(int _x, int _y) : x(_x), y(new int(_y)) {}

        //Our smart deep copy
        abc(const abc &obj) {
            x = obj.x;
            y = new int(*obj.y);
        }

        void print() const
        {
            printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);
        }

        ~abc() {
            delete y;
        }
};

int main()
{
    abc a(1, 2);
    cout << "Print int a\n";
    a.print();

    //abc b(a);
    abc b = a; // Call hota hai, Copy constructor
    cout << "Print int b\n";
    b.print();
    *b.y = 20;
    cout << "Print int b\n";
    b.print();

    cout << "Print int a\n";
    a.print();
    return 0;
}