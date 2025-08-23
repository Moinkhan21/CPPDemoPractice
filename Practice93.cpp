#include <iostream>
using namespace std;

void solve(int** ptr){
    ptr = ptr + 1;
}

void solve1(int** ptr){
    *ptr = *ptr + 1;
}

void solve2(int** ptr){
    **ptr = **ptr + 1;
}

int main() {
    int x = 12;
    int* p = &x;
    int** q = &p;

    solve(q);
    cout << x << endl;

    solve1(q);
    cout << x << endl;

    solve2(q);
    cout << x << endl;
}