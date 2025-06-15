#include <iostream> 
#include <vector>
using namespace std;

int main() {

    vector<int> arr;

    int ans = (sizeof(arr) / sizeof(int)); // Calculate the size of the vector in bytes and divide by size of int
    cout << ans << endl; // Output the size of the vector

    cout << arr.size() << endl; // Output the size of the vector using the size() method
    cout << arr.capacity() << endl; // Output the capacity of the vector

    // Add elements to the vector
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    //Printing array elements
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " "; // Output each element in the vector
    }
    cout << endl; // New line after printing all elements

    //remove the last element
    arr.pop_back(); // Remove the last element from the vector

    //Printing array elements
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " "; // Output each element in the vector
    }
    cout << endl; // New line after printing all elements

    return 0; // Return 0 to indicate successful execution
}