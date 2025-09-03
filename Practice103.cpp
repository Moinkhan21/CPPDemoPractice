#include <iostream>
using namespace std;

void print(int arr[], int n, int i){
    //Base case
    if(i >= n){
        return;
    }

    // if( n == 0 ){
    //     return;
    // }

    // One case solve
    cout << arr[i] << " ";
    // cout << arr[0] << " ";

    // Recursive case (Recursion will handle the rest)
    print(arr, n, i + 1);
    // print(arr + 1, n - 1);
}

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int i = 0;
    print(arr, n, i);
    //print(arr, n);

    return 0;
}