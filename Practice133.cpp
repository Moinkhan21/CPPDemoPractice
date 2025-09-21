#include <iostream>
using namespace std;

int partition(int arr[], int s, int e){
    //Step1: Choose pivotelement
    int pivotIndex = s;
    int pivotElement = arr[s];

    //Step2: Find right position for pivot element ans place it there
    int count = 0;
    for(int i = s + 1; i <= e; i++){
        if(arr[i] <= pivotElement){
            count++;
        }
    }

    //Jab main loop se bahar hua, toh mere paas pivot ki right position ka index ready he
    int rightIndex = s + count;
    swap(arr[pivotIndex], arr[rightIndex]);

    //update pivotIndex to its final position
    pivotIndex = rightIndex;

    //Step 3: Left me chote ans right me bade
    int i = s;
    int j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivotElement){
            i++;
        }
        while(arr[j] < pivotElement){
            j--;
        }

        //2 case ho sakte he
        //A => You found the elements to swap
        //B => No need to swap
        if(i < pivotIndex && j > pivotIndex)
            swap(arr[i], arr[j]);
    }
    return pivotIndex;
}

void quickSort(int arr[], int s, int e){
    //Base case
    if(s >= e){
        return;
    }

    //Partition logic, return pivotIndex
    int p = partition(arr, s, e);

    //Recursive calls
    //Pivot element -> left
    quickSort(arr, s, p - 1);

    //Pivot element -> right
    quickSort(arr, p + 1, e);
}

int main() {
    int arr[] = {8, 1, 3, 4, 20, 50, 30};
    int n = 7;

    int s = 0;
    int e = n - 1;
    quickSort(arr, s, e);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
