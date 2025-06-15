#include <iostream>
using namespace std;

int main() {

    // 🔹 First Task: Print arr[0], arr[7], arr[1], arr[6], ...
    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size = 8;
    int start = 0;
    int end = size - 1;

    while(start <= end){
        if(start == end){
            // If start and end meet (middle element), print only once
            cout << arr[start] << " ";
        }
        else{
            // Print element from start and end
            cout << arr[start] << " ";
            cout << arr[end] << " ";
        }

        start++;
        end--;
    }

    cout << endl;

    // 🔹 Second Task: Reverse the array {1,2,3,4,5,6} to {6,5,4,3,2,1}
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    int size1 = 6;
    int start1 = 0;
    int end1 = size1 - 1;

    while(start1 <= end1){
        // Swap elements from both ends
        swap(arr1[start1], arr1[end1]);
        start1++;
        end1--;
    }

    // Print reversed array
    for(int i = 0; i < size1; i++){
        cout << arr1[i] << " ";
    }

    cout << endl;

    // 🔹 Third Task: Print arr2[0], arr2[6], arr2[1], arr2[5], ..., arr2[3]
    int arr2[7] = {10, 20, 30, 40, 50, 60, 70};
    int size2 = 7;
    int start2 = 0;
    int end2 = size2 - 1;

    while(start2 <= end2){
        if(start2 == end2){
            // Only one middle element left
            cout << arr2[start2] << " ";
        }
        else{
            // Print from both ends
            cout << arr2[start2] << " ";
            cout << arr2[end2] << " ";
        }

        start2++;
        end2--;
    }

    cout << endl;

    // 🔹 Fourth Task: Reverse the array {1,2,3,4,5} to {5,4,3,2,1}
    int arr3[5] = {1, 2, 3, 4, 5};
    int size3 = 5;
    int start3 = 0;
    int end3 = size3 - 1;

    while(start3 <= end3){
        swap(arr3[start3], arr3[end3]);
        start3++;
        end3--;
    }

    // Print reversed array
    for(int i = 0; i < size3; i++){
        cout << arr3[i] << " ";
    }

    cout << endl;

    return 0;
}
