#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int row=0; row<n; row++) {
        for(int col=0; col<=row; col++) {
            if(col == 0 || col == row || row == n-1) {
                cout << col + 1;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    cout << "----------------------------------------" << endl;
    

    for(int i=0; i<n; i++) {
        for (int j=i+1; j<=n; j++) {
            if(j == i+1 || j == n || i == 0) {
                cout << j;
            } else {
                cout << " ";
            }
        }
        cout << endl;
    }
}

