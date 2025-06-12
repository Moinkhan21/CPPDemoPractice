#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void inc(int arr[], int size) {
    arr[0] += 10; // Increment the first element by 10

    printArray(arr, size); // Print the array after incrementing
}

bool find(int arr1[], int size1, int key) {
    for(int i = 0; i < size1; i++) {
        if(arr1[i] == key) {
            return true; // Key found
        }
    }
    return false; // Key not found
}

int main() {

    int arr[] = {5, 6};
    int size = 2;
    inc(arr, size);

    printArray(arr, size);

    int arr1[5] = {1, 2, 3, 4, 5};
    int size1 = 5;

    cout << "Enter the key to find" << endl;
    int key;
    cin >> key;

    if(find(arr1, size1, key)){
        cout << "Key found in the array." << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }

    int arr2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size2 = 10;

    int key2 = 11;

    bool flag = 0;

    for(int i = 0; i < size2; i++) {
        if(arr2[i] == key2) {
            flag = 1; // Key found
        }
    }

    if(flag) {
        cout << "Key found in the array." << endl;
    } else {
        cout << "Key not found in the array." << endl;
    }

    return 0;
}