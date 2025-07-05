#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n; // Take input for number of rows

    // Input validation: Ensure the input is not greater than 9
    if (n > 9) {
        cout << "Please enter a value <= 9" << endl;
        return 0; // Exit if input is invalid
    }

    // Loop through each row (0-based index)
    for (int i = 0; i < n; i++) {

        // Determine the first index in the row where the number should be printed
        int start_num_index = 8 - i;

        // The number to be printed in this row (1-based)
        int num = i + 1;

        // This keeps track of how many times the number should be printed in the current row
        int count_num = num;

        // Print characters in the current row
        for (int j = 0; j < 17; j++) { // 17 columns (fixed width)

            // If the current column is the position to print a number and there are still numbers left
            if (j == start_num_index && count_num > 0) {
                cout << num; // Print the number (same number multiple times in each row)

                // Move to the next column position for the next number
                start_num_index += 2; // Numbers are placed at alternate columns

                // Decrease the count of how many times the number needs to be printed
                count_num--;
            }
            else {
                cout << "*"; // Print '*' at all other positions
            }
        }

        cout << endl; // Move to the next line after each row
    }
}
