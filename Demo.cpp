#include <iostream>
using namespace std;

int main() {

    int age = 18;
    (age >= 18) ? cout << "Can Vote" : cout << "Cannot Vote" << endl;
   
    int number = 10;
    (number % 2 == 0) ? cout << "Even Number" : cout << "Odd Number" << endl;

    int a = 5, b = 10;

    int ans1 = (++a) * (--b);
    cout << "Result of (++a) * (b--): " << ans1 << endl;

    int ans2 = (++a) * (b--);
    cout << "Result of (a++) * (b--): " << ans2 << endl;

    int ans3 = (a++) * (--b);
    cout << "Result of (a++) * (--b): " << ans3 << endl;
    
    int ans4 = (a++) * (b--);
    cout << "Result of (a++) * (b--): " << ans4 << endl;

    int n = 528;

    cout << "Using while loop" << endl;
    // Print each digit of the number using a while loop
    while(n != 0) {
        int remainder = n % 10;
        cout << remainder << " " << endl;

        n /= 10; // Remove the last digit
    }

    cout << endl;

    cout << "for loop" << endl;

    int num = 528;
    // Print each digit of the number using a for loop
    for(; num != 0; num /= 10) {
        int remainder = num % 10;
        cout << remainder << " " << endl;
    }

    return 0;
}