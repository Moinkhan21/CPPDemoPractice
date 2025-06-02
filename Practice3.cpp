#include <iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    if(n > 9) {
        cout << "Please enter a value <= 9" << endl;
        return 0;
    }

    for(int i=0; i<n; i++) {
        int start_num_index = 8-i;
        int num = i+1;
        int count_num = num;
        for(int j=0; j<17; j++) {
            if(j == start_num_index && count_num > 0) {
                cout << num;
                start_num_index += 2;  // Move to the next position for the next number
                count_num--;  // Decrease the count of numbers to print
            }
            else {
                cout << "*";  
            }
        }
        cout << endl;  // Move to the next row
    }

    // Separator lines for clarity between patterns
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;

    int c = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) {
            cout << c;  // Print the current number
            c++;
        }
        cout << endl;  // Move to the next row
    }

    int start = c-n;
    for(int i=0; i<n; i++) {
        int k = start;
        for(int j=0; j<n-i-1; j++) {
            cout << k;  // Print the current number
            k++;
        }
        start = start - (n-i-1);  // Update start for the next row
        cout << endl;  // Move to the next row
    }
}