#include <iostream>
using namespace std;    

void findMissing(int *a, int n) {
    
    // Step 1: Mark the indices of the elements in the array
    for(int i = 0; i < n; i++){
        int index = abs(a[i]); 
        if(a[index - 1] > 0) {
            a[index - 1] *= -1; // Mark the index as visited
        }
    }

    // Step 2: Find the first index that is not marked
    for(int i = 0; i < n; i++) {
        if(a[i] > 0) {
            cout << "Missing element: " << i + 1 << endl; // Output the missing element
            return;
        }
    }
}

    
int main() {
    
    int n;
    int a[] = {1, 3, 5, 3, 4};
    n = sizeof(a)/sizeof(int);
    findMissing(a, n);

    return 0;
}