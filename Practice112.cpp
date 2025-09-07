#include <iostream>
using namespace std;

void printSubsequences(string str, string output, int i){

    //Base case
    if(i >= str.length()){
        cout << output << endl;
        return;
    }

    //Recursive case
    //Exclude ith character
    printSubsequences(str, output, i + 1);

    //Include ith character
    //Below line is responsible for concatenation of output string and ith charact character of str string
    output.push_back(str[i]); //output = output + str[i];

    printSubsequences(str, output, i + 1);
}

int main() {

    string input = "abc";
    string output = "";

    int i = 0;
    printSubsequences(input, output, i);
    return 0;
}