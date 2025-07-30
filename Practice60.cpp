#include <iostream>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;

void replaceSpaces(char sentence[]) {

    int i = 0;
    int n = strlen(sentence);

    for(int i = 0; i < n; i++){
        if(sentence[i] == ' '){
            sentence[i] = '@';
        }
    }
}

bool checkPalindrome(char word[]){
    int i = 0;
    int n = strlen(word);
    int j = n - 1;

    while(i <= j){
        if(word[i] != word[j]){
            return false; // Not a palindrome
        }
        else{
            i++;
            j--;
        }
    }
    return true; // It's a palindrome
}

 void convertIntoUpperCase(char word1[]){
    int n = strlen(word1);
    for(int i = 0; i < n; i++){
        word1[i] = word1[i] - 'a' + 'A'; // Convert to uppercase
    }
 }

int main() {
    char sentence[100];
    cout << "Enter a sentence: ";
    cin.getline(sentence, 100); // Using getline to read the entire line including spaces

    cout << "Original sentence: " << sentence << endl;

    replaceSpaces(sentence);

    cout << "Modified sentence: " << sentence << endl;

    
    //T.C : O(n)
    //S.C : O(1)

    // Example usage of checkPalindrome
    char word[100] = "madam";
    cout << "Palindrome check: " << checkPalindrome(word) << endl;
    //T.C : O(n)
    //S.C : O(1)

    char word1[100] = "hello";
    cout << "Original word: " << word1 << endl;
    convertIntoUpperCase(word1);
    cout << "Converted to uppercase: " << word1 << endl;
    //T.C : O(n)
    //S.C : O(1)

    return 0;
}