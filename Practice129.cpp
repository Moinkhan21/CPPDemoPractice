#include <iostream>
#include <string>
using namespace std;

bool isMatchHelper(string&s, int si, string&p, int pi){
    //Base case
    if(si == s.size() && pi == p.size()){
        return true;
    }
    if(si == s.size() && pi < p.size()){
        while(pi < p.size()){
            if(p[pi] != '*') return false;
            pi++;
        }
        return true;
    }

    //Single char matching
    if(s[si] == p[pi] || '?' == p[pi]){
        return isMatchHelper(s, si+1, p, pi+1);
    }

    if(p[pi] == '*'){
        //Treat '*' as empty or null
        bool caseA = isMatchHelper(s, si+1, p, pi+1);

        //Let '*' consume one char.
        bool caseB = isMatchHelper(s, si+1, p, pi);
        return caseA || caseB;
    }

    //char doesn't match
    return false;
}

bool isMatch(string s, string p){
    int si = 0; //pointer index for s string
    int pi = 0; //pointer index for p string

    return isMatchHelper(s, si, p, pi);
}

int main(){
    string s, p;
    cin >> s >> p;
    if(isMatch(s, p)){
        cout << "Match!" << endl;
    } else {
        cout << "No match!" << endl;
    }
    return 0;
}
