#include <iostream>

using namespace std;

int main() {
    char ch[10] = "Babbar";
    char* c = ch;

    cout  << ch << endl;
    cout  << &ch << endl;
    cout << ch[0] << endl;

    cout << &c << endl;
    cout << *c << endl;
    cout << c << endl;

    char name[9] = "SherBano";
    char* c1 = &name[0];

    cout << name << endl;
    cout << &name << endl;
    cout << *(name + 3) << endl;
    cout << c1 << endl;
    cout << &c1 << endl;
    cout << *(c1 + 3) << endl;
    cout << c1 + 2 << endl; // Print the address of the third character in name
    cout << *c1 << endl; // Print the first character of name
    cout << c1 + 8 << endl; // Print the address of the last character in name

    return 0;
}