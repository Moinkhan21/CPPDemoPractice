#include <iostream>
using namespace std;

long long int factorial(long long int n) {

    long long int fact = 1;  // Initialize factorial to 1

    if (n == 0 || n == 1) {  // Base case: factorial of 0 or 1 is 1
        return 1;            // Return 1 for base case
    } else {
        for(int i = 1; i <= n; i++) { // Loop from 0 to n-1
            fact = fact * i;  // Multiply fact by the current number
        }
        return fact;
    }
}

bool checkEven(int n) {
    if (n % 2 == 0) {  // Check if the number is even
        return true;   // Return true if even
    } else {
        return false;  // Return false if odd
    }
}

bool checkOdd(int num) {
    if ((num&1) != 0) {  // Check if the number is even
        return true;   // Return true if even
    } else {
        return false;  // Return false if odd
    }
}

float circle_area(float radius){
        float area = 3.14 * radius * radius;  // Calculate the area of the circle
        return area;  // Return the calculated area
    }

int main() {
    float radius;
    cin >> radius;  // Read the radius of the circle
    float area = circle_area(radius);  // Calculate the area of the circle
    cout << "Area of the circle is: " << area << endl;  // Output the area

    int n;
    cin >> n;
    bool isEven = checkEven(n);  // Check if the number is even

    if (isEven) {
        cout << n << " is even number." << endl;  // Output if the number is even
    } else {
        cout << n << " is odd number." << endl;  // Output if the number is odd
    }

    int num;
    cin >> num;
    bool isOdd = checkOdd(num);  // Check if the number is even

    if (isOdd) {
        cout << num << " is odd number." << endl;  // Output if the number is even
    } else {
        cout << num << " is even number." << endl;  // Output if the number is odd
    }

    long long int ans = factorial(n);  // Calculate the factorial of n
    cout << "Factorial of " << n << " is: " << ans << endl;  // Output the factorial
    return 0;  // Return 0 to indicate successful execution
}