#include<iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int s, int e, int& target){

    //Base case
    //Case 1 -> Key/Target not found
    //s > e -> invalid array
    if(s > e)
        return -1;
    
    int mid = s + (e - s) / 2;

    //Case 2 -> Key/Target found
    if(arr[mid] == target)
        return mid;

    //Recursive case
    //arr[mid] < key -> right me search
    if(arr[mid] < target){
        return binarySearch(arr, mid + 1, e, target);
    }
    else{
        //arr[mid] > key -> left me search
        return binarySearch(arr, s, mid - 1, target);
    }

    //Recursive case using ternary operator
    // return (arr[mid] < target)?
    //           binarySearch(arr, mid + 1, e, target) :
    //           binarySearch(arr, s, mid - 1, target);

}

int main(){
    vector<int> v{10, 20, 40, 60, 70, 90, 99};
    int target = 99;
    int n = v.size();
    int s = 0;
    int e = n - 1;
    int ans = binarySearch(v, s, e, target);

    cout << "Answer is : " << ans << endl;
}