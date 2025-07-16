#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> arr) {
    int s = 0;
    int e = arr.size() - 1;
    int mid = s + (e - s) / 2;

    while(s <= e) {
        if(s == e) {
            //single element 
            return s;
        }
        if(mid <= e && arr[mid] > arr[mid + 1]) {
            //mid is pivot
            return mid;
        }
        if(mid - 1 >= s && arr[mid - 1] > arr[mid]) {
            //mid-1 is pivot
            return mid - 1;
        }

        if(arr[s] > arr[mid]){
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1; // No pivot found, array is not rotated
}

int binarySearch(vector<int> arr, int s, int e, int target){
    int mid = s + (e - s) / 2;

    while(s <= e){
        if(arr[mid] == target) {
            return mid; // Target found
        }
        if(arr[mid] > target) {
            e = mid - 1; // Search in left half
        } else {
            s = mid + 1; // Search in right half
        }
        mid = s + (e - s) / 2;
    }
    return -1; // Target not found
}

int search(vector<int>& nums, int target) {

    int pivotIndex = findPivot(nums);
    int ans = 0;
    if(target >= nums[0] && target <= nums[pivotIndex]) {
        // Search in the left part
        ans = binarySearch(nums, 0, pivotIndex, target);
    } else {
        // Search in the right part
        ans = binarySearch(nums, pivotIndex + 1, nums.size() - 1, target);
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int result = search(arr, target);
    if(result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}