#include <iostream>
using namespace std;

class abc
{
    public:
        int x, y;

        abc() : x(0), y(0) {}

        static void print(){
            //no this pointer accessible
            printf("I an in Static %s\n", __FUNCTION__);
        }
};

int main() {
    abc obj1;
    obj1.print();
    abc::print();
    abc obj2;
    abc::print();
    abc::print();
    return 0;
}