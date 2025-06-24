#include <iostream>
using namespace std;

int findDuplicate(int arr[], int n){

    while(arr[0] != arr[arr[0]]){
        swap(arr[0], arr[arr[0]]);
    }
    return arr[0];
}

int main(){
    
    int n;
    cout << "Enter a number of elements: ";
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout << endl;

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    int duplicate = findDuplicate(arr, n);

    // Output the result
    if (duplicate != -1) {
        cout << "Duplicate element found: " << duplicate << endl;
    } else {
        cout << "No duplicate element found." << endl;
    }

    return 0;
}