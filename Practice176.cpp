#include <iostream>
using namespace std;

class Box
{
    int width;

public:

    //Ctor
    Box(int _w) : width(_w){};

    int getWidth() const
    {
        return width;
    }

    void setWidth(int _val)
    {
        width = _val;
    }
};

int main() {

    Box b(5);
    cout << b.getWidth() << endl;
    return 0;
}