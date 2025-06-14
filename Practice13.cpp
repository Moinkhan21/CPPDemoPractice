#include <iostream>
using namespace std;

int main() {

    int arr[8] = {10, 20, 30, 40, 50, 60, 70, 80};
    int size = 8;

    int start = 0;
    int end = size - 1;

    while(start <= end){

        if(start > end){
            break;
        }
        if(start == end){
            cout << arr[start] << " ";
        }
        else{
            cout << arr[start] << " ";
            cout << arr[end] << " ";
        }

        start++;
        end--;
    }

    cout << endl;

    int arr1[6] = {1, 2, 3, 4, 5, 6};
    int size1 = 6;

    int start1 = 0;
    int end1 = size1 - 1;

    while(start1 <= end1){

        swap(arr1[start1], arr1[end1]);
        start1++;
        end1--;

    }

    for(int i = 0; i < size1; i++){
        cout << arr1[i] << " ";
    }

    cout << endl;

    int arr2[7] = {10, 20, 30, 40, 50, 60, 70};
    int size2 = 7;

    int start2 = 0;
    int end2 = size2 - 1;

    while(start2 <= end2){

        if(start2 > end2){
            break;
        }
        if(start2 == end2){
            cout << arr2[start2] << " ";
        }
        else{
            cout << arr2[start2] << " ";
            cout << arr2[end2] << " ";
        }

        start2++;
        end2--;
    }

    cout << endl;

    int arr3[5] = {1, 2, 3, 4, 5};
    int size3 = 5;

    int start3 = 0;
    int end3 = size3 - 1;

    while(start3 <= end3){

        swap(arr3[start3], arr3[end3]);
        start3++;
        end3--;

    }

    for(int i = 0; i < size3; i++){
        cout << arr3[i] << " ";
    }

    cout << endl;

    return 0;

}