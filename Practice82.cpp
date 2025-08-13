#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convert(string s, int numRows){
    if(numRows == 1) return s;

    vector<string> zigzag(numRows);

    int i = 0, row = 0;
    bool direction = 1; // 1 -> Top -> Bottom

    while(true){
        if(direction){
            while(row < numRows && i < s.size()){
                zigzag[row++].push_back(s[i++]);
            }
            row = numRows - 2;
        }
        else{
            while(row >= 0 && i < s.size()){
                zigzag[row--].push_back(s[i++]);
            }
            row = 1;
        }
        if(i >= s.size()) break;
        direction = !direction;
    }
    string result = "";
    for(int i = 0; i < numRows; i++){
        result += zigzag[i];
        cout << zigzag[i] << endl; // Debugging output to see the zigzag pattern
    }
    return result;
}

int main() {
    string str = "Hello, World!";
    cout << convert(str, 3) << endl;
    return 0;
}