#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> arr, int target) {
    int s = 0;
    int e = arr.size() - 1;

    int mid = s + (e - s) / 2;

    while(s <= e) {
        if(arr[mid] == target)
          return mid; // Target found, return index
        if(mid - 1 >= 0 && arr[mid - 1] == target) //mid - 1 >= s
          return mid - 1; // Target found at mid - 1
        if(mid + 1 < arr.size() && arr[mid + 1] == target) // mid + 1 <= e
          return mid + 1; // Target found at mid + 1

        if(arr[mid] < target) {
            s = mid + 2; // Move to the right half, skipping one element
        } else {
            e = mid - 2; // Move to the left half, skipping one element
        }
        mid = s + (e - s) / 2; // Recalculate mid
    }
    return -1; // Target not found

}

int main() {
    vector<int> arr{10, 3, 40, 20, 50, 80, 70};
    int target = 40;

    int ans = binarySearch(arr, target);
    cout << "Index of " << target << " is: " << ans << endl;
}