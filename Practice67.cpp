#include <iostream>     // For standard I/O operations (cin, cout)
#include <string>       // For using string data type and functions
#include <vector>       // For using vector container
#include <algorithm>    // For using STL algorithms like sort()
using namespace std;

// Custom comparator function for sorting characters in descending order
bool cmp(char first, char second) {
    return first > second; // Return true if first character is greater (for descending order)
}

// Custom comparator function for sorting integers in descending order
bool compare(int a, int b) {
    return a > b; // Return true if a is greater than b (for descending order)
}

int main() {

    // Declare and initialize a string
    string s = "babbar";

    // Sort the string in descending order using custom comparator `cmp`
    sort(s.begin(), s.end(), cmp); // s.begin() is the start iterator, s.end() is the end iterator
                                   // `cmp` tells sort how to compare characters (descending)

    // Print the sorted string
    cout << s << endl;  // Output will be: "rbbbaa" because it sorts characters in reverse lexicographical order

    // Declare and initialize a vector of integers
    vector<int> v = {1, 2, 3, 4, 5};

    // Sort the vector in descending order using custom comparator `compare`
    sort(v.begin(), v.end(), compare);  // Sorts vector elements from highest to lowest

    // Print the sorted vector
    for(int num : v) {
        cout << num << " ";  // Will output: 5 4 3 2 1
    }

    return 0;
}
