#include <iostream>
using namespace std;

int x = 2; //Global variable

int main() {

    x = 4; //Global x
    int x = 20; //Local to main() function
    cout << x << endl; //Accessing local x
    cout << ::x << endl; //Accessing global with ::

    {
        int x = 50; //Local to this block
        cout << x << endl; //Accessing block x
        cout << ::x << endl; //Accessing global with ::
    }
    
    return 0;

}