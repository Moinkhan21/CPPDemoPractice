#include <iostream>
#include <vector>
using namespace std;

int main() {

    vector<int> arr{10, 1, 7, 6, 14, 9};
    int n = arr.size();

    // Insertion sort algorithm
    for(int round = 1; round < n; round++){
        //Step A - fetch
        int val = arr[round];

        //Step B - Compare and shift
        int j = round - 1; // Start from the last sorted element
        for(; j >= 0; j--){
            if(arr[j] > val){
                //Step C - Shift the element
                arr[j + 1] = arr[j];
            }
            else{
                //No need to shift, break the loop
                break;
            }
        }

        //Step D - Place the value/ Copy the value
        arr[j + 1] = val;
    }

    // Printing the sorted array
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}