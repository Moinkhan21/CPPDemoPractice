#include <iostream>
using namespace std;

float circle_area(float radius){
        float area = 3.14 * radius * radius;  // Calculate the area of the circle
        return area;  // Return the calculated area
    }

int main() {
    float radius;
    cin >> radius;  // Read the radius of the circle
    float area = circle_area(radius);  // Calculate the area of the circle
    cout << "Area of the circle is: " << area << endl;  // Output the area
}