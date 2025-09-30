#include <iostream>
#include <vector>
using namespace std;

void mergeInPlace(vector<int>& arr, int start, int mid, int end){
    int total_len = end - start + 1;
    int gap = total_len / 2 + total_len % 2; // ceil of total_len/2
    while(gap > 0) {
        int i = start, j = start + gap;
        while(j <= end){
            if(arr[i] > arr[j]){
                swap(arr[i], arr[j]);
            }
            i++;
            j++;
        }
        gap = gap <= 1 ? 0 : (gap / 2) + (gap % 2); // ceil of gap/2
    }
}

void mergeSort(vector<int>& arr, int start, int end){
    if(start >= end) return;
    int mid = start + (end - start) / 2; // int mid = (start + end) >> 1;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    mergeInPlace(arr, start, mid, end);
}

vector<int> sortArray(vector<int>& arr) {
    mergeSort(arr, 0, (int)arr.size() - 1);
    return arr;
}

int main() {
    vector<int> arr = {5, 2, 3, 1};
    vector<int> sortedArr = sortArray(arr);
    cout << "Sorted array: ";
    for(int num : sortedArr) {
        cout << num << " ";
    }
    cout << endl; // Expected: 1 2 3 5
    return 0;
}