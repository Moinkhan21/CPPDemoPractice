#include <iostream>
using namespace std;

void numberShow(int num) {
    cout << num << endl;
}

inline void numberShowMultipleOfTwo(int num) {
    cout << num*2 << endl;
}

int main(){
    numberShow(10);
    numberShowMultipleOfTwo(10);
    return 0;
}