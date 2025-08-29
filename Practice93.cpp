#include <iostream>
using namespace std;

// Function that takes a double pointer (pointer to pointer) as input
// This function increments the address of ptr (local copy only),
// so it will NOT affect the original pointer in main.
void solve(int** ptr){
    ptr = ptr + 1;  // Moves ptr itself to point to the next memory location
}

// Function that takes a double pointer (pointer to pointer)
// This time, we change what *ptr points to (i.e., the address stored in 'p')
// So, the pointer 'p' inside main will shift to the next integer address
// But the value of x is NOT modified here.
void solve1(int** ptr){
    *ptr = *ptr + 1;  // Moves the pointer 'p' forward (not the value it points to)
}

// Function that takes a double pointer (pointer to pointer)
// This modifies the actual value stored in the integer 'x'
// because we dereference twice (**ptr) to directly access the value of x.
void solve2(int** ptr){
    **ptr = **ptr + 1;  // Increment the value of x
}

int main() {
    int x = 12;       // An integer variable
    int* p = &x;      // 'p' is a pointer pointing to x
    int** q = &p;     // 'q' is a double pointer pointing to 'p'

    // Call solve(q)
    // This only changes the local copy of q, so no effect in main
    solve(q);
    cout << x << endl;  // Output: 12 (unchanged)

    // Call solve1(q)
    // This changes 'p' to point to the next memory location after x
    // but does not change the value of x
    solve1(q);
    cout << x << endl;  // Output: 12 (still unchanged)

    // Call solve2(q)
    // This directly increments the value of x
    solve2(q);
    cout << x << endl;  // Output: 13

    return 0;
}
