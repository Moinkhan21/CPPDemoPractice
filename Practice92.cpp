#include <iostream>
using namespace std;

void util(int* p){
    p = p + 1;
}

void util1(int* s){
    *s = *s + 1;
}


int main() {
    int a = 5;
    int* p = &a;
    int** q = &p;

    cout << &a << endl;
    cout << a << endl;
    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl;
    cout << q << endl;
    cout << &q << endl;
    cout << *q << endl;
    cout << **q << endl;

    int b = 5;
    int* r = &b;

    cout << "Before" << endl;

    cout << b << endl;
    cout << r << endl;
    cout << *r << endl;

    util(p);

    cout << "After" << endl;

    cout << b << endl;
    cout << r << endl;
    cout << *r << endl;

    int c = 5;
    int* s = &c;

    cout << "Before" << endl;

    cout << c << endl;
    cout << s << endl;
    cout << *s << endl;

    util1(s);

    cout << "After" << endl;

    cout << c << endl;
    cout << s << endl;
    cout << *s << endl;


    return 0;
}