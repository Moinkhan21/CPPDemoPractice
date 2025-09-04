#include <iostream>
using namespace std;

int checkKey(string& str, int i, int& n, char& key){
    //Base case
    if(i >= n) {
        //Key not found in whole string
        return -1;
    }

    //Solve only one case
    if(str[i] == key)
        return i;

    //Recursive call
    return checkKey(str, i+1, n, key);

}

int main() {
    string str = "lovebabbar";
    int n = str.length();

    char key = 'r';

    int i = 0;
    int ans = checkKey(str, i, n, key);

    cout << "Answer is: " << ans << endl;

    return 0;
}