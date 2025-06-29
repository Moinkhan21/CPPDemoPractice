#include <iostream>
using namespace std;

// Function to print all elements of the array
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " "; // Print each element with a space
    }
    cout << endl; // New line after printing all elements
}

// Function to increment the first element of the array by 10
void inc(int arr[], int size) {
    arr[0] += 10; // Increment the first element by 10

    // Display the updated array inside this function
    cout << "Array after incrementing first element by 10 (inside inc function): ";
    printArray(arr, size); 
}

// Function to find a key in an array
bool find(int arr1[], int size1, int key) {
    for(int i = 0; i < size1; i++) {
        if(arr1[i] == key) {
            return true; // Key found
        }
    }
    return false; // Key not found
}

// Main function
int main() {

    // ======================
    // 1. Demonstrate passing array to function and modifying
    // ======================
    int arr[] = {5, 6}; // Declare an array of size 2
    int size = 2;

    // Call function to increment the first element
    inc(arr, size);

    // Print array after incrementing (outside the function)
    cout << "Array after inc() function (from main): ";
    printArray(arr, size);

    // ======================
    // 2. Search for a key entered by the user
    // ======================
    int arr1[5] = {1, 2, 3, 4, 5};
    int size1 = 5;

    cout << "Enter the key to find: ";
    int key;
    cin >> key; // Input key from the user

    // Call function to check if key is present in arr1
    if(find(arr1, size1, key)) {
        cout << "Key found in the array." << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }

    // ======================
    // 3. Another example of searching for a fixed key using a flag
    // ======================
    int arr2[10] = {1,2,3,4,5,6,7,8,9,10};
    int size2 = 10;
    int key2 = 11; // Predefined key to search
    bool flag = 0; // Boolean flag to track if key is found

    // Loop through arr2 to search for key2
    for(int i = 0; i < size2; i++) {
        if(arr2[i] == key2) {
            flag = 1; // Key found
            break;
        }
    }

    // Output result based on flag
    if(flag) {
        cout << "Key found in the array." << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }

    return 0; // Successful program termination
}
