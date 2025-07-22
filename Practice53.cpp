#include<iostream>
#include <vector>
using namespace std;

int binarySearch(int a[], int start, int end, int x){
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(a[mid] == x){
            return mid;
        }
        else if(a[mid] < x){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1; // Element not found
}

int expSearch(int a[], int n, int x){
    if (a[0] == x) return 0;
    int i = 1;
    while (i < n && a[i] <= x) {
        i *= 2; //i *= 2 or i <<= 1;
    }
    return binarySearch(a, i / 2, min(i, n - 1), x);// binary search in the subarray
}

int main() {
    int a[] = {3, 4, 5, 6, 11, 13, 14, 15, 56, 70};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 13;
    int ans = expSearch(a, n, x);
    cout << "Element " << x << " is at index: " << ans << endl;
    return 0;
}