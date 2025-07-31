#include <iostream>
#include <string>
using namespace std;

// Function to calculate the length of a character array (C-style string)
int getLengh(char name1[]) {
    int length = 0;
    int i = 0;
    
    // Iterate through the array until the null character '\0' is reached
    while(name1[i] != '\0') {
        i++;
        length++;
    }

    // Return the final length
    return length;
}

// Function to reverse a character array (C-style string)
void reverseCharArray(char name1[]) {
    int i = 0;
    
    // Get the length of the string using the custom function
    int n = getLengh(name1);
    
    // Initialize the right pointer
    int j = n - 1;

    // Swap characters from both ends moving towards the center
    while(i <= j) {
        swap(name1[i], name1[j]);
        i++;
        j--;
    }
}

int main() {
    // Define a character array to store the name
    char name[15];

    // Ask the user to enter the first name
    cout << "Enter your name: ";

    // Use getline to read the entire line including spaces into 'name'
    cin.getline(name, 15); 
    cout << endl;

    // Print the first entered name
    cout << "Your name is: " << name << endl;

    // Define another character array to store the second name
    char name1[15];

    // Ask the user to enter the second name
    cin.getline(name1, 15); // Again using getline to support spaces

    // Print the second entered name
    cout << "Your second name is: " << name1 << endl;

    // Display the length of the second name using custom function
    cout << "Length of name: " << getLengh(name1) << endl;

    // Uncomment this to use built-in function to compare results
    // cout << "Length of name: " << strlen(name1) << endl;

    // Indicate that reversing is about to happen
    cout << "Reversing the second name..." << endl;

    // Print the string before reversing
    cout << "Before reversing: " << name1 << endl;

    // Reverse the character array
    reverseCharArray(name1);

    // Print the reversed string
    cout << "After reversing: " << name1 << endl;

    return 0;
}
