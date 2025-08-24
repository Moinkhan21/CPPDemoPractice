#include <iostream>
using namespace std;

void solve(int num){
    num++;
}

void solve1(int& val){
    val++;
}

int main() {
    int a = 5;
    int b = 5;

    solve(a);
    solve1(b);

    cout << a << endl;
    cout << b << endl;

    return 0;
}