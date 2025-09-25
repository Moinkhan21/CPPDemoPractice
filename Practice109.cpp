#include <iostream>
using namespace std;

// Function to print digits of a number in correct order
void printDigits(int n){
    // ✅ Base case:
    // When number becomes 0, stop recursion
    if(n == 0){
        return;
    }

    // Reduce the number by removing the last digit
    int newValueOfN = n / 10;

    // 🔁 Recursive call to process remaining digits (towards most significant digit)
    printDigits(newValueOfN);

    // 🎯 Solve one case (print last digit after recursion comes back)
    int digit = n % 10;
    cout << digit << " ";
}

int main(){
    int n = 0;  // Number whose digits we want to print

    // Special case:
    // If number is 0, we should directly print 0 
    // (otherwise recursion will not handle this correctly)
    if(n == 0){
        cout << 0 << endl;
    }

    // Call recursive function
    printDigits(n);

    return 0;
}
