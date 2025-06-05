#include <iostream>
using namespace std;

// Function to calculate the factorial of a number
long long int factorial(long long int n) {
    long long int fact = 1;  // Initialize factorial result

    if (n == 0 || n == 1) {
        return 1;  // Factorial of 0 or 1 is always 1
    } else {
        for (int i = 1; i <= n; i++) {
            fact *= i;  // Multiply current number to get factorial
        }
        return fact;
    }
}

// Function to check if a number is even using modulo
bool checkEven(int n) {
    return (n % 2 == 0);
}

// Function to check if a number is odd using bitwise AND
bool checkOdd(int num) {
    return ((num & 1) != 0);
}

// Function to calculate the area of a circle
float circle_area(float radius) {
    return 3.14 * radius * radius;  // Area = πr²
}

int main() {
    // Step 1: Area of a Circle
    float radius;
    cout << "Enter radius of the circle: ";
    cin >> radius;

    float area = circle_area(radius);
    cout << "Area of the circle is: " << area << endl;

    // Step 2: Check Even/Odd using modulo
    int n;
    cout << "Enter an integer to check even/odd (method 1): ";
    cin >> n;

    if (checkEven(n)) {
        cout << n << " is an even number." << endl;
    } else {
        cout << n << " is an odd number." << endl;
    }

    // Step 3: Check Odd/Even using bitwise
    int num;
    cout << "Enter another integer to check odd/even (method 2): ";
    cin >> num;

    if (checkOdd(num)) {
        cout << num << " is an odd number." << endl;
    } else {
        cout << num << " is an even number." << endl;
    }

    // Step 4: Factorial calculation
    long long int ans = factorial(n);
    cout << "Factorial of " << n << " is: " << ans << endl;

    return 0;  // Successful execution
}
