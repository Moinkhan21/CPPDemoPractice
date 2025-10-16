#include <iostream>
using namespace std;

class abc
{
    public:
        int x;
        int *y;

        abc(int _x, int _y) : x(_x), y(new int(_y)) {}

        void print() const
        {
            printf("X:%d\nPTR Y:%p\nContent of Y (*y):%d\n\n", x, y, *y);
        }
};

int main()
{
    abc a(1, 2);
    a.print();
    return 0;
}