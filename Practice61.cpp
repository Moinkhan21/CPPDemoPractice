#include <iostream>
#include <string>
using namespace std;

bool compareString(string str1, string str2){
    if(str1.length() != str2.length()){
        return false; // Strings are of different lengths
    }
    else{
        int j = 0;
        for(int i = 0; i < str1.length(); i++){
            if(str1[i] != str2[i])
            {
                return false; // Characters at position i are different
            }
            else{
                j++;
            }
        }
    }
    return true; // All characters matched
}

int main() {
    //String create
    string str;

    //input a string (cin >> str)
    cout << "Enter a string: ";
    //getline(cin, str);
    cin >> str;

    //print the string
    cout << "You entered: " << str << endl;
    //String length
    cout << "Length of the string: " << str.length() << endl;
    //String empty check
    cout << "Is the string empty? " << str.empty() << endl;
    //String push_back
    str.push_back('*');
    cout << "After push_back: " << str << endl;
    //String pop_back
    str.pop_back();
    cout << "After pop_back: " << str << endl;
    //Substring
    cout << str.substr(0, 3) << endl; // Prints first 3 characters

    //Comparing strings
    string str1 = "Hello";
    string str2 = "Hey";

    if(str1.compare(str2) == 0) {
        cout << "Strings are equal" << endl;
    } else {
        cout << "Strings are not equal" << endl;
    }

    if(compareString(str1, str2)) {
        cout << "Strings are equal" << endl;
    } else {
        cout << "Strings are not equal" << endl;
    }

    string x = "abcd";
    string y = "bcda";
    string z = "cbcd";

    cout << "Comparing x and y: " << endl;
    cout << x.compare(y) << endl; // Compares lexicographically
    cout << z.compare(y) << endl; // Compares lexicographically

    string str3 = "Hello Jee Kaise Ho?";
    string str4 = "Kaise";
    string str5 = "Everyone";

    cout << "Finding substring in str3: " << endl;
    cout << str3.find(str4) << endl; // Returns index of first occurrence of str4 in str3

    if(str3.find(str5) != string::npos) {
        cout << "Substring found!" << endl;
    } else {
        cout << "Substring not found!" << endl;
    }

    string str6 = "This is a string";
    string str7 = "Mobile";
    string str8 = "Phone";

    cout << "Original string: " << str6 << endl;
    str6.replace(0, 4, str7); // Replaces first 4 characters with str7
    cout << "After replace: " << str6 << endl;

    cout << "Original string: " << str6 << endl;
    str6.replace(12, 6, str8); // Replaces "is" with "Phone"
    cout << "After replace: " << str6 << endl;

    string str9 = "Hello World";
    cout << "Original string str9: " << str9 << endl;
    str9.erase(6, 5); // Removes 5 characters starting from index 6
    cout << "After erase: " << str9 << endl;

    string str10 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Original string str10: " << str10 << endl;
    str10.erase(0, 5); // Removes first 5 characters
    cout << "After erase: " << str10 << endl;

    string str11 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << "Original string str11: " << str11 << endl;
    str11.erase(20, 5); // Removes last 5 characters
    cout << "After erase: " << str11 << endl;


    return 0;
}