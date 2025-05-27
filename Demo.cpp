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

    int digit[] = { 8, 2, 3, 7};

    int ans = 0;

    for(int i = 0; i < 4; i++) {
        ans = (ans * 10) + digit[i];
    }

    cout << ans << endl;

    int m = 3;

    int answer = 0;

    while(m != 0) {
        if(m & 1) {
            //found one set bit, so increment set bit count
            answer += 1;
        }

        //right shift
        m = m >> 1;
    }

    cout << "Number of set bits: " << answer << endl;

    int km;
    cout << "Enter a number in kilometers: " << endl;
    cin >> km;

    cout << "The number in meters is: " << km * 1000 << endl;
    cout << "The number in centimeters is: " << km * 100000 << endl;
    cout << "The number in miles is: " << km * (1/1.609) << endl;

    return 0;
}