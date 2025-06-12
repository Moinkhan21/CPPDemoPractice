#include <iostream>
#include <climits>
using namespace std;

int main() {

    int arr[] = {0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1};
    int size = 15;

    int numZero = 0;
    int numOne = 0;

    for(int i = 0; i < size; i++) {
        //if zero found, increment numZero
        if(arr[i] == 0) {
            numZero++;
        }
        //if one found, increment numOne
        if(arr[i] == 1) {
            numOne++;
        }
    }

    cout << "Number of 0s: " << numZero << endl;
    cout << "Number of 1s: " << numOne << endl;

    int arr1[] = {2, 4, 6, 1, 3, 7, 9, 12, 56, 43, 21};
    //int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size1 = 11; // Size of arr1

    //intitalize the maxi variable with the minimum possible integer value
    int maxi = INT_MIN;

    for(int i = 0; i < size1; i++) {
        //if the current element is greater than maxi, update maxi
        if(arr1[i] > maxi) {
            maxi = arr1[i];
        }
    }

    cout << "Maximum value in arr1: " << maxi << endl;

    int arr2[] = {2, 4, 6, 1, 3, 7, 9, 12, 56, 43, 21};
    //int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size2 = 11; // Size of arr2

    //intitalize the mini variable with the maximum possible integer value
    int mini = INT_MAX;

    for(int i = 0; i < size2; i++) {
        //if the current element is lower than mini, update mini
        if(arr1[i] < mini) {
            mini = arr2[i];
        }
    }

    cout << "Minimum value in arr2: " << mini << endl;

    return 0;
}