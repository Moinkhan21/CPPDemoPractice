#include <iostream>
using namespace std;

int main() {
    int row = 5;  // Number of rows in the 2D array
    int col = 3;  // Number of columns in the 2D array

    /*
        Step 1: Create a double pointer (int** arr)
        -------------------------------------------
        This pointer will store the addresses of multiple 1D arrays.
        Each 1D array will represent one row of the 2D array.
    */
    int** arr = new int*[row]; // Allocate memory for 'row' number of int* (row pointers)

    /*
        Step 2: Allocate memory for each row
        ------------------------------------
        For each row pointer, allocate memory for 'col' integers.
        This effectively creates a dynamic 2D array with 'row x col' elements.
    */
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col]; // Each row gets its own 1D array of 'col' integers
    }

    /*
        Step 3: (Optional) Initialize array elements
        ---------------------------------------------
        Note: Currently, we did NOT initialize elements.
        In C++, dynamically allocated memory using 'new' is not auto-initialized.
        So, arr[i][j] will contain garbage (random) values unless assigned explicitly.
        
        Example initialization (if needed):
        arr[i][j] = i + j;  // Just a sample value
    */

    /*
        Step 4: Print the 2D array
        ----------------------------
        This loop prints all elements of the array.
        Since the array is not initialized, this will print garbage values.
    */
    cout << "Printing 2D array (uninitialized values):" << endl;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << arr[i][j] << " "; // Access element using arr[rowIndex][colIndex]
        }
        cout << endl;
    }

    /*
        Step 5: Deallocate memory (VERY IMPORTANT)
        ------------------------------------------
        - Each 'new' must be matched with a 'delete' to avoid memory leaks.
        - Since we used 'new[]' (array form of new), we must use 'delete[]'.
        - We first delete each row, then delete the main pointer array.
    */
    for (int i = 0; i < row; i++) {
        delete [] arr[i]; // Delete each dynamically allocated row
    }
    delete [] arr; // Delete the array of row pointers

    /*
        After deallocation:
        - The memory previously used by arr is now freed.
        - Accessing arr[i][j] after this point will cause undefined behavior.
    */

    return 0; // Program ends successfully
}
