#include <iostream>   // Header file for input-output operations (cin, cout)
#include <vector>     // Header file for using the vector container in C++
using namespace std;

int main() {

    /*
        Step 1: Creating a 2D vector (Dynamic 2D array)
        -----------------------------------------------
        - Syntax: vector<vector<int>> arr(rows, vector<int>(cols, initial_value));
        - Here:
            → 'arr' is a vector of vectors (i.e., a 2D array)
            → It has 5 rows and 6 columns
            → Each element is initialized to 0
        - Unlike raw arrays or double pointers, vectors automatically handle
          memory allocation and deallocation, so no manual delete[] is needed.
    */
    vector<vector<int>> arr(5, vector<int>(6, 0));

    /*
        Step 2: Printing the 2D vector elements
        ---------------------------------------
        - We use two nested loops:
            → Outer loop for rows (i)
            → Inner loop for columns (j)
        - Initially, all elements are 0 (as set during initialization).
    */
    cout << "Printing 2D vector elements (initialized to 0):" << endl;
    for (int i = 0; i < 5; i++) {           // Loop through each row
        for (int j = 0; j < 6; j++) {       // Loop through each column
            cout << arr[i][j] << " ";       // Print each element
        }
        cout << endl;                       // Move to next line after each row
    }

    /*
        Step 3: Automatic memory management
        -----------------------------------
        - Since we're using vectors, memory cleanup is automatic.
        - When 'arr' goes out of scope (end of main function),
          all dynamically allocated memory inside the vector is released.
        - This makes vectors safer and more convenient than raw pointers or new/delete.
    */

    return 0; // End of the program
}
