#include <iostream>
#include <string>

using namespace std;

void removeOccure(string& s, string& part){
    int found = s.find(part);
    if(found != string::npos) {
        //Part string has been located
        //Please remove it
        string left_part = s.substr(0, found);
        string right_part = s.substr(found + part.size(), s.size());
        s = left_part + right_part;
        removeOccure(s, part);
    }
    else{
        //base case
        //all the occurrences of part has been removed from s.
        return;
    }
}

string removeOccurrences(string s, string part) {
    removeOccure(s, part);

    return s;
}

int main(){
    string s, part;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter part string to be removed: ";
    cin >> part;
    string ans = removeOccurrences(s, part);
    cout << ans << endl;
    return 0;
}