#include <iostream>     // For standard I/O operations (cin, cout)
#include <cstring>      // For using C-style stringss      
#include <map>     
#include <algorithm>    // For using STL algorithms like sort()
using namespace std;

int main() {
    // Creation of map
        map<int, char> meraMap;

    //Insert elements in map
        meraMap[1] = 'a';
        meraMap[2] = 'b';
        meraMap[3] = 'c';

    //accessing elements in map
        cout << "Your ans is: " << meraMap[1] << endl; // Outputs: a
        cout << "Your ans is: " << meraMap[2] << endl; // Outputs: b
        cout << "Your ans is: " << meraMap[3] << endl; // Outputs: c
}