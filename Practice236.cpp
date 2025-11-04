#include <iostream>
using namespace std;

// ==========================================
// ✅ Class: Stack (Two Stacks in One Array)
// ==========================================
class Stack {
public:
    int *arr;   // Dynamic array to hold elements
    int size;   // Size of array
    int top1;   // Top pointer for Stack 1
    int top2;   // Top pointer for Stack 2

    // ✅ Constructor: initializes the two stacks
    Stack(int size) {
        arr = new int[size];
        this->size = size;
        top1 = -1;       // Stack 1 starts from left (index 0)
        top2 = size;     // Stack 2 starts from right (index size - 1)

        // Initialize array with 0 for clarity (optional)
        for (int i = 0; i < size; i++)
            arr[i] = 0;
    }

    // ✅ Push in Stack 1
    void push1(int data) {
        if (top2 - top1 == 1) {
            // No available space between stacks
            cout << "⚠️ Overflow in Stack 1" << endl;
        } else {
            top1++;           // Move top1 forward
            arr[top1] = data; // Insert element
        }
    }

    // ✅ Pop from Stack 1
    void pop1() {
        if (top1 == -1) {
            // No elements in Stack 1
            cout << "⚠️ Underflow in Stack 1" << endl;
        } else {
            arr[top1] = 0; // Optional: clear value
            top1--;         // Move top1 backward
        }
    }

    // ✅ Push in Stack 2
    void push2(int data) {
        if (top2 - top1 == 1) {
            // No available space
            cout << "⚠️ Overflow in Stack 2" << endl;
        } else {
            top2--;           // Move top2 backward
            arr[top2] = data; // Insert element
        }
    }

    // ✅ Pop from Stack 2
    void pop2() {
        if (top2 == size) {
            // Stack 2 is empty
            cout << "⚠️ Underflow in Stack 2" << endl;
        } else {
            arr[top2] = 0; // ✅ FIXED: assignment instead of comparison
            top2++;         // Move top2 forward
        }
    }

    // ✅ Print current state of both stacks
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

    // ✅ Destructor to free dynamically allocated memory
    ~Stack() {
        delete[] arr;
    }
};

// ==========================================
// ✅ Main Function — Testing Two Stacks
// ==========================================
int main() {
    // Create a stack array of size 10
    Stack s(10);

    // Push elements in Stack 1
    s.push1(10); s.print();
    s.push1(20); s.print();
    s.push1(30); s.print();
    s.push1(40); s.print();
    s.push1(50); s.print();

    // Push elements in Stack 2
    s.push2(100); s.print();
    s.push2(110); s.print();
    s.push2(120); s.print();
    s.push2(130); s.print();
    s.push2(140); s.print(); // Should show Overflow message

    // Pop a few elements for testing
    s.pop1(); s.print();
    s.pop2(); s.print();

    return 0;
}
