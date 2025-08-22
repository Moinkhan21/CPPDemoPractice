#include <iostream>
using namespace std;

int gcd(int A, int B){
    if(A == 0) return B;
    if(A == 0) return A;

    while(A > 0 && B > 0){
        if(A > B){
            A = A - B;
        }
        else{
            B = B - A;
        }
    }
    return A == 0 ? B : A;

}

int main(){
    int A;
    cout << "Enter A: ";
    cin >> A;

    int B;
    cout << "Enter B: ";
    cin >> B;

    int ans = gcd(A, B);

    cout << "GCD of A and B is: " << ans << endl;

}