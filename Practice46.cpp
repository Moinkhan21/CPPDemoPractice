#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    vector<int> arr{5, 4, 3, 2, 1};
    int n = arr.size();

    //Selection sort algorithm
    //Outer loop -> (n - 1) rounds
    for(int i = 0; i < n - 1; i++) {
        int minIndex = i; // Assume the first element is the minimum
        //Inner loop -> Find the minimum element in the unsorted part OR index of the minimum element in range [i, n]
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j; // Update minIndex if a smaller element is found
            }
        }
        // Swap the found minimum element with the first element
        swap(arr[i], arr[minIndex]);
    }

    //Printing the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}