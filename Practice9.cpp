#include <iostream>   // For input/output operations
#include <vector>     // For using vector data structure

using namespace std;

// Function to convert Celsius to Fahrenheit and Kelvin
vector<double> convertTemperature(double celsius) {
    double fahrenheit = (celsius * 9.0 / 5.0) + 32.0;  // Celsius to Fahrenheit
    double kelvin = celsius + 273.15;                 // Celsius to Kelvin

    vector<double> v;
    v.push_back(fahrenheit); // Add Fahrenheit to the vector
    v.push_back(kelvin);     // Add Kelvin to the vector

    return v; // Return the vector with both temperature conversions
}

int main() {
    double celsius;
    cout << "Enter temperature in Celsius: ";
    cin >> celsius;

    // Call the conversion function
    vector<double> result = convertTemperature(celsius);

    // Display the converted temperatures
    cout << "Fahrenheit: " << result[0] << endl;
    cout << "Kelvin: " << result[1] << endl;

    return 0;
}
