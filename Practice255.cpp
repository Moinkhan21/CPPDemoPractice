#include <iostream>
#include <stack>
using namespace std;

// ============================================================================
// CLASS: NStack
// PURPOSE:
//    Implements **N independent stacks inside a single array** using three
//    auxiliary arrays: `top[]`, `next[]`, and `a[]`.
//
// DATA STRUCTURES USED:
//    1. a[size]     → Main array that stores all stack elements.
//    2. top[n]      → Stores top index of each stack (size = number of stacks).
//    3. next[size]  → Helps maintain a free list + linking elements inside stacks.
//    4. freeSpot    → Points to the first free index in array `a`
//
// HOW IT WORKS:
//    - `next[]` maintains a linked list of free spots.
//    - When pushing, we take first free index from this list.
//    - When popping, we return that index back into the free list.
// ============================================================================
class NStack {
    int *a;      // Main array to store values of all stacks
    int *top;    // Top indices for each of the N stacks
    int *next;   // Helps track next free position OR next element in a stack
    int n;       // Number of stacks
    int size;    // Size of main array
    int freeSpot;// Index of first free element in array `a`

public:

    // ========================================================================
    // CONSTRUCTOR
    // _n = number of stacks
    // _s = total size of the array to store elements
    // ========================================================================
    NStack(int _n, int _s) : n(_n), size(_s) {

        freeSpot = 0;                     // First free index is 0
        a = new int[size];                // Allocate main array
        top = new int[n];                 // Allocate top array for each stack
        next = new int[size];             // Allocate next array

        // Initialize all stacks to empty → top[i] = -1
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        }

        // Initialize free list → next[i] = i + 1
        for (int i = 0; i < size; i++) {
            next[i] = i + 1;
        }
        next[size - 1] = -1;              // Last element has no next free spot
    }

    // ========================================================================
    // FUNCTION: push(X, m)
    // Insert value X into stack number m
    // RETURNS:
    //    true  → insertion successful
    //    false → overflow (no free spot available)
    // ========================================================================
    bool push(int X, int m) {

        // If freeSpot = -1 → no free indices left → overflow
        if (freeSpot == -1) {
            return false;
        }

        // 1. Allocate index from free list
        int index = freeSpot;

        // 2. Update freeSpot to next free index
        freeSpot = next[index];

        // 3. Insert the value in main array
        a[index] = X;

        // 4. Link new element to the previous top of stack m
        next[index] = top[m - 1];

        // 5. Update top pointer for stack m
        top[m - 1] = index;

        return true;
    }

    // ========================================================================
    // FUNCTION: pop(m)
    // Removes top element from stack number m
    // RETURNS:
    //     popped element if stack not empty
    //     -1 if stack underflow
    // ========================================================================
    int pop(int m) {

        // If stack m is empty
        if (top[m - 1] == -1) {
            return -1; // Underflow condition
        }

        // 1. Get index of top element of stack m
        int index = top[m - 1];

        // 2. Move top pointer to next element in that stack
        top[m - 1] = next[index];

        // 3. Store popped element
        int poppedElement = a[index];

        // 4. Add this index back to free list
        next[index] = freeSpot;

        // 5. Update freeSpot to this index
        freeSpot = index;

        return poppedElement;
    }

    // Destructor to release memory
    ~NStack() {
        delete[] a;
        delete[] top;
        delete[] next;
    }
};

// ============================================================================
// MAIN FUNCTION — Testing NStack
// ============================================================================
int main() {

    // Create 3 stacks in a single array of size 6
    NStack s(3, 6);

    // Push operations into various stacks
    cout << s.push(10, 1) << endl;   // Push 10 into stack 1
    cout << s.push(12, 1) << endl;   // Push 12 into stack 1
    cout << s.push(13, 1) << endl;   // Push 13 into stack 1

    cout << s.push(14, 2) << endl;   // Push 14 into stack 2
    cout << s.push(15, 3) << endl;   // Push 15 into stack 3

    // Pop operations
    cout << s.pop(1) << endl;        // Pop from stack 1 → should be 13
    cout << s.pop(2) << endl;        // Pop from stack 2 → should be 14

    return 0;
}
