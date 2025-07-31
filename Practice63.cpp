#include <iostream>
#include <string>
using namespace std;

string removeOccurrences(string s, string part){
    int pos = s.find(part);
    while(pos != string::npos){
        s.erase(pos, part.length());
        pos = s.find(part);
    }
    return s;
}

int main() {
    // Input a string
    string str;
    cout << "Enter a string: ";
    cin >> str;

    // Input the part to remove
    string part;
    cout << "Enter the part to remove: ";
    cin >> part;

    // Remove occurrences of part from str
    string result = removeOccurrences(str, part);

    // Print the result
    cout << "String after removing occurrences of '" << part << "': " << result << endl;

    return 0;
}