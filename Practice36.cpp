#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;
    int mid = (start + end) / 2;

    while(start <= end){
        int element = arr[mid];

        if(element == target) {
            return mid;
        }
        else if(target < element) {
            //Search in the left half
            end = mid - 1;
        }
        else {
            //Search in the right half
            start = mid + 1;
        }

        mid = (start + end) / 2; // Update mid after changing start or end
    }
    return -1; // Target not found
}


int main() {

    int arr[] = {2, 4, 6, 8, 10, 12, 16};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 8;

    int indexOftarget = binarySearch(arr, n, target);
    if (indexOftarget == -1) {
        cout << "Element not found" << endl;
    } else {
        cout << "Element found at index: " << indexOftarget << endl;
    }
}