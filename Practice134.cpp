#include <iostream>
using namespace std;

void printPermutation(string &str, int i){
    //Base case
    if(i >= str.length()) {
        cout << str << " ";
        return;
    }

    //Swapping
    for(int j = i; j < str.length(); j++) {

        //Swap
        swap(str[i], str[j]);

        //Recursive call
        printPermutation(str, i + 1);
        
        //Backtracking - to recreate the original input string
        swap(str[i], str[j]);
    }
}

int main() {
    string str = "abc";
    int i = 0;
    printPermutation(str, i);

    return 0;
}