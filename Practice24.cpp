#include <iostream>
using namespace std;

int findDuplicate(int arr[], int n){
    int ans = -1;

    for(int i = 0; i < n; i++){

        int index = abs(arr[i]);

        //aleardy visited?
        if(arr[index] < 0){
            ans = index;
            break;
        }

        //Visited mark;
        arr[index] *= -1;
    }
 return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n]; // Declare array of size n

    // Input elements
    cout << "Enter " << n << " elements: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Print array
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call function and print duplicate
    int duplicate = findDuplicate(arr, n);
    if (duplicate != -1) {
        cout << "Duplicate element found: " << duplicate << endl;
    } else {
        cout << "No duplicate element found." << endl;
    }

    return 0;
}
