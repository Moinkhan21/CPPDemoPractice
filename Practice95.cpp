#include <iostream>
using namespace std;

// Function 1: Pass pointer by VALUE
void solve1(int* q){
    // q is a local copy of the pointer passed from main()
    // Incrementing q will move the pointer to the next memory location,
    // BUT since q is passed by value, the original pointer in main() is NOT modified.
    q = q + 1; 
}

// Function 2: Pass pointer by REFERENCE
void solve2(int*& q){
    // Here q is a REFERENCE to the pointer passed from main().
    // Any modification to q directly affects the original pointer in main().
    q = q + 1; 
}

// Function 3: Pass pointer to modify the VALUE it points to
void solve(int* val){
    // Dereferencing the pointer to change the actual value stored in memory.
    // *val means the data at the memory location.
    *val = *val + 1; // Increment the value stored at that address.
} 

int main(){
    int a = 12;  // Normal integer variable

    //int *p = &a; // Pointer storing the address of a
    //solve(p);   // Passing pointer p
    solve(&a);   // Passing the address of 'a' directly to modify its value

    int b = 5;   // Another integer variable
    int *q = &b; // Pointer q points to the address of b

    // Prints updated value of 'a'
    cout << a << endl;  
    // Output: 13 (because solve(&a) incremented the value of a)

    // Demonstrating solve1 (Pass by VALUE)
    cout << "Before " << q << endl; // Prints the memory address q is holding (address of b)
    solve1(q);  // Tries to move q to next memory location, BUT only modifies the local copy
    cout << "After " << q << endl;  // q remains unchanged (still points to b)

    cout << endl;

    // Demonstrating solve2 (Pass by REFERENCE)
    cout << "Before " << q << endl; // Prints the memory address q is holding (address of b)
    solve2(q);  // Actually moves q to the next memory location (since q passed by reference)
    cout << "After " << q << endl;  // q now points to a DIFFERENT memory location (next to b)

    return 0;
}
