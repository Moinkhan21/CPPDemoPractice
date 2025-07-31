#include <iostream>
#include <string>
using namespace std;

// Custom function to compare two strings character-by-character
bool compareString(string str1, string str2) {
    // If lengths differ, the strings can't be equal
    if (str1.length() != str2.length()) {
        return false;
    } else {
        // Compare each character at the same position
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
                return false; // Characters don't match
            }
        }
    }
    return true; // All characters matched
}

int main() {
    // Declare a string variable
    string str;

    // Take input from user
    cout << "Enter a string: ";
    cin >> str;  // You can also use getline(cin, str) for full line input

    // Display the string entered by the user
    cout << "You entered: " << str << endl;

    // Display the length of the string
    cout << "Length of the string: " << str.length() << endl;

    // Check if the string is empty
    cout << "Is the string empty? " << str.empty() << endl;

    // Add a character to the end of the string
    str.push_back('*');
    cout << "After push_back: " << str << endl;

    // Remove the last character from the string
    str.pop_back();
    cout << "After pop_back: " << str << endl;

    // Display a substring: first 3 characters from index 0
    cout << "Substring (first 3 characters): " << str.substr(0, 3) << endl;

    // Comparing two strings using built-in compare() method
    string str1 = "Hello";
    string str2 = "Hey";

    if (str1.compare(str2) == 0) {
        cout << "Strings are equal (using compare method)" << endl;
    } else {
        cout << "Strings are not equal (using compare method)" << endl;
    }

    // Comparing two strings using custom function
    if (compareString(str1, str2)) {
        cout << "Strings are equal (using custom function)" << endl;
    } else {
        cout << "Strings are not equal (using custom function)" << endl;
    }

    // More string comparison using compare() for lexicographical comparison
    string x = "abcd";
    string y = "bcda";
    string z = "cbcd";

    cout << "Comparing x and y (lexicographically): " << x.compare(y) << endl;
    cout << "Comparing z and y (lexicographically): " << z.compare(y) << endl;

    // Searching for a substring inside a string
    string str3 = "Hello Jee Kaise Ho?";
    string str4 = "Kaise";
    string str5 = "Everyone";

    cout << "Finding substring \"" << str4 << "\" in str3: ";
    cout << str3.find(str4) << endl; // Prints the index if found

    // Check if str5 exists in str3
    if (str3.find(str5) != string::npos) {
        cout << "Substring \"" << str5 << "\" found!" << endl;
    } else {
        cout << "Substring \"" << str5 << "\" not found!" << endl;
    }

    // Replace part of a string with another string
    string str6 = "This is a string";
    string str7 = "Mobile";
    string str8 = "Phone";

    cout << "Original string: " << str6 << endl;
    str6.replace(0, 4, str7); // Replace "This" with "Mobile"
    cout << "After replacing first word: " << str6 << endl;

    str6.replace(12, 6, str8); // Replace "string" with "Phone"
    cout << "After replacing last word: " << str6 << endl;

    // Demonstrate string erasing
    string str9 = "Hello World";
    cout << "Original string str9: " << str9 << endl;
    str9.erase(6, 5); // Erase "World"
    cout << "After erase (index 6, length 5): " << str9 << endl;

    // Erase from the beginning of the string
    string str10 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Original string str10: " << str10 << endl;
    str10.erase(0, 5); // Remove first 5 characters
    cout << "After erasing first 5 characters: " << str10 << endl;

    // Erase from the end of the string
    string str11 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Original string str11: " << str11 << endl;
    str11.erase(20, 5); // Remove 5 characters starting from index 20
    cout << "After erasing last 5 characters: " << str11 << endl;

    return 0;
}
