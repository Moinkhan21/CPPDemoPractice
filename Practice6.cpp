#include <iostream>
using namespace std;

bool checkEven(int n) {
    if (n % 2 == 0) {  // Check if the number is even
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
}