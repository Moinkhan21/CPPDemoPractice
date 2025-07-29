#include <iostream>
#include <string>

using namespace std;

int getLenght(char name1[]) {
    int length = 0;
    int i = 0;
    while(name1[i] != '\0') {
        i++;
        length++;
    }
    return length;
}

void reverseCharArray(char name1[]) {
    int i = 0;
    int n = getLenght(name1);
    int j = n - 1;

    while(i <= j) {
        swap(name1[i], name1[j]);
        i++;
        j--;
    }
}

int main() {

    // char name[15];
    // cout << "Enter your name: ";

    // for(int i = 0; i < 15; i++){
    //     cin >> name[i];
    // }
    // cout << endl;
    
    // cout << "Your name is: " << name << endl;

    char name[15];
    cout << "Enter your name: ";
    //cin >> name;

    cin.getline(name, 15); // Using getline to read the entire line including spaces
    cout << endl;
    cout << "Your name is: " << name << endl;

    char name1[15];
    cin.getline(name1, 15); // Reading another name
    cout << "Your second name is: " << name1 << endl;
    cout << "Length of name: " << getLenght(name1) << endl;
    //cout << "Length of name: " << strlen(name1) << endl;

    cout << "Reversing the second name..." << endl;
    cout << "Before reversing: " << name1 << endl;
    reverseCharArray(name1);
    cout << "After reversing: " << name1 << endl;


    return 0;
}