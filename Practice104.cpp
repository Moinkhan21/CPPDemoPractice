#include <iostream>
#include <climits>
using namespace std;

void findMax(int arr[], int n, int i, int& maxi){

    //Base case
    if(i >= n){
        // If array is finished, whole array is traversed
        // So return
        return;
    }

    // Solve only one case ( We have to solve only one case here)
    //Check current element for max
    if(arr[i] > maxi){
        maxi = arr[i];
    }

    //Recursive call
    findMax(arr, n, i+1, maxi);
}

void findMin(int arr[], int n, int i, int& mini){

    //Base case
    if(i >= n){
        // If array is finished, whole array is traversed
        // So return
        return;
    }

    // Solve only one case ( We have to solve only one case here)
    //Check current element for max
    if(arr[i] < mini){
        mini = arr[i];
    }

    //Recursive call
    findMin(arr, n, i+1, mini);
}

int main(){

    int arr[] = {10, 30, 21, 44, 32, 17, 19, 66};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int maxi = INT_MIN;
    int mini = INT_MAX;
    int i = 0;

    findMax(arr, n, i, maxi);
    findMin(arr, n, i, mini);

    cout << "Maximum number is: " << maxi << endl;
    cout << "Minimum number is: " << mini << endl;
    return 0;
}