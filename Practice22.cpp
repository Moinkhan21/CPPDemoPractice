#include <iostream>
using namespace std;

// Function to move all negative numbers to the left side of the array
void moveAllNegToLeft(int* a, int n) {
    // Dutch National Flag Algorithm (2-pointer approach)

    int l = 0;         // Left pointer starting from the beginning
    int h = n - 1;     // Right pointer starting from the end

    while (l < h) {

        // If the left element is already negative, it's in the correct place
        if (a[l] < 0) {
            l++; // Move left pointer to the right
        }
        // If the right element is positive, it's already in the correct place
        else if (a[h] > 0) {
            h--; // Move right pointer to the left
        }
        // If left is positive and right is negative, swap them
        else {
            swap(a[l], a[h]);
            // Do not move l and h in this else block immediately
            // because the swapped elements need to be re-evaluated in next loop
        }
    }
}

int main() {
    // Define an array of positive and negative integers
    int a[] = {1, 2, -3, 4, -5, 6};
    
    // Calculate size of the array
    int n = sizeof(a) / sizeof(int);

    // Call function to move all negative elements to the left
    moveAllNegToLeft(a, n);

    // Output the modified array
    cout << "Array after moving all negatives to the left: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0; // Indicate successful execution
}
