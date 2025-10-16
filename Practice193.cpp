#include <iostream>
using namespace std;

class abc
{
    public:
        int x;
        int *y;

        abc(int _x, int _y) : x(_x), y(new int(_y)) {}

        // Default dumb copy constructor: it does Shallow copy
        abc(const abc &obj) {
            x = obj.x;
            y = obj.y;
        }

        void print() const
        {
            printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);
        }
};

int main()
{
    abc a(1, 2);
    a.print();

    //abc b(a);
    abc b = a;
    b.print();
    return 0;
}