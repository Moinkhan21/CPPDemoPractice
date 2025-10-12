#include <iostream>  // Header file for input and output operations (cin, cout)
using namespace std;

int main() {
    int row = 5;  // Number of rows for the 2D array
    int col = 3;  // Number of columns for the 2D array

    /*
        Step 1: Create a double pointer (int** arr)
        -------------------------------------------
        - 'arr' will act as a pointer to a list of row pointers.
        - Each row pointer will later point to a dynamically allocated 1D array (representing each row).
        - This setup allows us to create a dynamic 2D array using heap memory.
    */
    int** arr = new int*[row]; // Allocate memory for 'row' number of integer pointers

    /*
        Step 2: Allocate memory for each row
        ------------------------------------
        - Each pointer in 'arr' now needs to point to a dynamically allocated 1D array.
        - Each row will contain 'col' integer elements.
    */
    for (int i = 0; i < row; i++) {
        arr[i] = new int[col]; // Allocate memory for each row (array of 'col' integers)
    }

    /*
        Step 3: Printing array elements
        --------------------------------
        - Here, we print each element of the 2D array.
        - NOTE: Since we did NOT initialize the array,
                it will contain garbage (random) values.
        - Dynamically allocated memory in C++ is NOT automatically set to zero.
    */
    cout << "Printing 2D array (uninitialized values):" << endl;
    for (int i = 0; i < row; i++) {         // Loop through each row
        for (int j = 0; j < col; j++) {     // Loop through each column
            cout << arr[i][j] << " ";       // Print each element
        }
        cout << endl;                       // New line after each row
    }

    /*
        Step 4: Memory deallocation (not done in this version)
        ------------------------------------------------------
        - Since this version doesn't include memory deallocation,
          the allocated heap memory will not be released.
        - Always remember to use 'delete[]' to prevent memory leaks
          when using 'new[]' in real programs.
        
        Example:
            for (int i = 0; i < row; i++) {
                delete [] arr[i]; // Delete each row
            }
            delete [] arr; // Delete array of row pointers
    */

    return 0; // End of the program
}
