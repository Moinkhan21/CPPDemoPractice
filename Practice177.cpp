#include <iostream>
using namespace std;

class Box
{
    int width;
    
    //Ctor
    Box(int _w) : width(_w){};

public:
    int getWidth() const
    {
        return width;
    }

    void setWidth(int _val)
    {
        width = _val;
    }
};

int main(){

    // Box b(5);
    // Cout << b.getWidth() << endl;
    return 0;
}