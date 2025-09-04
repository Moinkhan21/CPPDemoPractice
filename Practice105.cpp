#include <iostream>
using namespace std;

bool checkKey(string& str, int& i, int& n, char& key){
    //Base case
    if(i >= n) {
        //Key not found in whole string
        return false;
    }

    //Solve only one case
    if(str[i] == key)
        return true;

    //Recursive call
    int newi = i + 1;
    bool ans = checkKey(str, newi, n, key);
    return ans;

}

int main() {
    string str = "lovebabbar";
    int n = str.length();

    char key = 'r';

    int i = 0;
    bool ans = checkKey(str, i, n, key);

    cout << "Answer is: " << ans << endl;

    return 0;
}