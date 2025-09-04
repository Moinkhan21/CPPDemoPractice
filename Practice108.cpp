#include <iostream>
#include <vector>
using namespace std;

void checkKey(string& str, int i, int& n, char& key, int& count){
    //Base case
    if(i >= n) {
        //Key not found in whole string
        return;
    }

    //Solve only one case
    if(str[i] == key){
        //Store in vector
        count++;
    }
        

    //Recursive call
    checkKey(str, i+1, n, key, count);

}

int main() {
    string str = "lovebabbar";
    int n = str.length();

    char key = 'b';

    int i = 0;
    int count = 0;

    checkKey(str, i, n, key, count);

    cout << "Printing counts: " << count << endl;
    
    return 0;
}