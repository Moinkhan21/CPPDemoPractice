#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> &arr, int& n, int i){

    //Base case
    if(i == n-1){
        return true;
    }

    //Solve only one case
    if(arr[i+1] < arr[i])
        return false;

    //Recursive call
    return checkSorted(arr, n, i+1);
}

int main() {

    vector<int> v{10, 20, 30, 50, 60};
    int n = v.size();
    int i = 0;

    bool isSorted = checkSorted(v, n, i);

    if(isSorted) {
        cout << "Array is sorted" << endl;
    }
    else {
        cout << "Array is not sorted" << endl;
    }

}