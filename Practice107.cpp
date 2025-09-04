#include <iostream>
#include <vector>
using namespace std;

void checkKey(string& str, int i, int& n, char& key, vector<int>& ans){
    //Base case
    if(i >= n) {
        //Key not found in whole string
        return;
    }

    //Solve only one case
    if(str[i] == key){
        //Store in vector
        ans.push_back(i);
    }
        

    //Recursive call
    return checkKey(str, i+1, n, key, ans);

}

int main() {
    string str = "lovebabbar";
    int n = str.length();

    char key = 'b';

    int i = 0;
    vector<int> ans;

    checkKey(str, i, n, key, ans);

    cout << "Printing answers: " << endl;
    for(auto val: ans){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}