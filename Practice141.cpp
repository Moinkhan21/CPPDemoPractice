#include <iostream>
#include <vector>
using namespace std;

long long mergeCount(vector<int>& arr, vector<int>& temp, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;
    long long invCount = 0;

    // Merge the two sorted halves while counting inversions
    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // arr[i] > arr[j] -> all remaining elements in left half [i..mid] form inversions with arr[j]
            temp[k++] = arr[j++];
            invCount += (long long)(mid - i + 1);
        }
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= end) temp[k++] = arr[j++];

    // Copy back to original array
    for (int idx = start; idx <= end; ++idx) arr[idx] = temp[idx];

    return invCount;
}

long long mergeSortCount(vector<int>& arr, vector<int>& temp, int start, int end) {
    if (start >= end) return 0;
    int mid = start + (end - start) / 2;
    long long count = 0;
    count += mergeSortCount(arr, temp, start, mid);
    count += mergeSortCount(arr, temp, mid + 1, end);
    count += mergeCount(arr, temp, start, mid, end);
    return count;
}

long long countInversions(vector<int> arr) {
    if (arr.empty()) return 0;
    vector<int> temp(arr.size());
    return mergeSortCount(arr, temp, 0, (int)arr.size() - 1);
}

int main() {
    vector<int> arr = {2, 4, 1, 3, 5};
    long long result = countInversions(arr);
    cout << "Number of inversions: " << result << endl; // Expected: 3
    return 0;
}
