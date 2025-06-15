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

    vector<int> arr2(10); // Create a vector of size 10
    cout << "Size of arr2: " << arr2.size() << endl; // Output the size of arr2
    cout << "Capacity of arr2: " << arr2.capacity() << endl; // Output the capacity of arr2

    for(int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " "; // Output each element in arr2 (initially all are 0)
    }

    cout << endl; // New line after printing all elements

    vector<int> arr3(5, 100); // Create a vector of size 5, initialized with 100

    for(int i = 0; i < arr3.size(); i++) {
        cout << arr3[i] << " "; // Output each element in arr3 (all are 100)
    }

    cout << endl; // New line after printing all elements

    int n;
    cout << "Enter the size of the vector: ";
    cin >> n; // Input the size of the vector from the user

    vector<int> arr4(n, 101); // Create a vector of size n, initialized with 101
    cout << "Size of arr4: " << arr4.size() << endl; // Output the size of arr4
    cout << "Capacity of arr4: " << arr4.capacity() << endl; // Output the capacity of arr4

    for(int i = 0; i < arr4.size(); i++) {
        cout << arr4[i] << " "; // Output each element in arr4 (all are 101)
    }

    cout << endl; // New line after printing all elements

    return 0; // Return 0 to indicate successful execution
}