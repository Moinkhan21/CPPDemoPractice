#include <iostream>
using namespace std;

void solve1(int* q){
    q = q + 1; //Pass by value
}

void solve2(int*& q){
    q = q + 1; //Pass by reference
}

void solve(int* val){
    *val = *val + 1;
} 

int main(){
    int a = 12;

    //int *p = &a;
    //solve(p);
    solve(&a);

    int b = 5;
    int *q = &b;

    cout << a << endl;

    cout << "Before " << q << endl;
    solve1(q);
    cout << "After " << q << endl;

    cout << endl;
    
    cout << "Before " << q << endl;
    solve2(q);
    cout << "After " << q << endl;

    return 0;
}
