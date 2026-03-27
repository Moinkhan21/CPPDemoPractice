#include <iostream>
using namespace std;

int main() {

  cout << "Enter the numbers of rows: " << endl;
  int n;
  cin >> n;

  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n - i - 1; j++) {
      cout << " ";
    }
    for(int j = 0; j < i + 1; j++) {
      cout << j + 1;
    }
    int start = i;
    for(int j = i; j >= 1; j--) {
      cout << start;
      start--;
    }
    cout << endl;
  }
  return 0;
}