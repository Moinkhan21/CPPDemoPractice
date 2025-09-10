#include <iostream>
#include <string>
using namespace std;

void reverse(string& s, int start, int end){
    //Base case
    if(start >= end){
        return;
    }

    //Ek case solution
    swap(s[start], s[end]);

    //Recursive call
    reverse(s, start + 1, end - 1);

}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    int start = 0;
    int end = s.size() - 1;

    reverse(s, start, end);
    cout << "Reversed string is: " << s << endl;

    return 0;
}