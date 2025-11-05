#include <iostream>
using namespace std;

// ==========================================
// ✅ Class: Stack (Two Stacks in One Array)
// ==========================================
// This implementation efficiently uses one array
// to hold two stacks — one growing from the left (Stack 1)
// and another growing from the right (Stack 2).
// This approach optimizes memory usage by sharing space.
class Stack {
public:
    int *arr;   // Dynamic array to hold elements
    int size;   // Total capacity of array
    int top1;   // Top pointer for Stack 1 (left side)
    int top2;   // Top pointer for Stack 2 (right side)

    // ✅ Constructor: initializes the two stacks
    Stack(int size) {
        arr = new int[size];   // Allocate memory for array
        this->size = size;
        top1 = -1;             // Stack 1 starts empty (leftmost side)
        top2 = size;           // Stack 2 starts empty (rightmost side)

        // Initialize array with zeros for clarity (optional)
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    // ✅ Push in Stack 1
    // Inserts a value into the left-growing stack
    void push1(int data) {
        // Check if there’s space between Stack 1 and Stack 2
        if (top2 - top1 == 1) {
            // No available space between stacks
            cout << "⚠️ Overflow in Stack 1" << endl;
        } else {
            top1++;           // Move top1 forward (to the right)
            arr[top1] = data; // Insert element into array
        }
    }

    // ✅ Pop from Stack 1
    // Removes the top element from Stack 1
    void pop1() {
        if (top1 == -1) {
            // No elements in Stack 1
            cout << "⚠️ Underflow in Stack 1" << endl;
        } else {
            arr[top1] = 0; // Optional: reset value for clarity
            top1--;         // Move top pointer backward
        }
    }

    // ✅ Push in Stack 2
    // Inserts a value into the right-growing stack
    void push2(int data) {
        // Check if there’s space between Stack 1 and Stack 2
        if (top2 - top1 == 1) {
            // No available space left in array
            cout << "⚠️ Overflow in Stack 2" << endl;
        } else {
            top2--;           // Move top2 backward (to the left)
            arr[top2] = data; // Insert element
        }
    }

    // ✅ Pop from Stack 2
    // Removes the top element from Stack 2
    void pop2() {
        if (top2 == size) {
            // Stack 2 is empty (no elements to pop)
            cout << "⚠️ Underflow in Stack 2" << endl;
        } else {
            arr[top2] = 0; // Clear the popped element (optional)
            top2++;         // Move top pointer forward (to the right)
        }
    }

    // ✅ Print current state of both stacks
    // Displays top pointers and current array elements
    void print() {
        cout << "\n--------------------------------\n";
        cout << "Top1 (Stack 1): " << top1 << endl;
        cout << "Top2 (Stack 2): " << top2 << endl;
        cout << "Array state: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n--------------------------------\n";
    }

    // ✅ Destructor
    // Frees dynamically allocated memory to prevent memory leaks
    ~Stack() {
        delete[] arr;
    }
};

// ==========================================
// ✅ Main Function — Testing Two Stacks
// ==========================================
// Demonstrates stack operations for both Stack 1 and Stack 2
int main() {
    // Create a stack array of size 10
    Stack s(10);

    // -------------------------------
    // Push elements in Stack 1 (left side)
    // -------------------------------
    s.push1(10); s.print();
    s.push1(20); s.print();
    s.push1(30); s.print();
    s.push1(40); s.print();
    s.push1(50); s.print();

    // -------------------------------
    // Push elements in Stack 2 (right side)
    // -------------------------------
    s.push2(100); s.print();
    s.push2(110); s.print();
    s.push2(120); s.print();
    s.push2(130); s.print();
    s.push2(140); s.print(); // Should show overflow message

    // -------------------------------
    // Pop a few elements from each stack
    // -------------------------------
    s.pop1(); s.print();  // Remove one element from Stack 1
    s.pop2(); s.print();  // Remove one element from Stack 2

    return 0;
}
