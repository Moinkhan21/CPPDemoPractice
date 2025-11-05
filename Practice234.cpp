#include <iostream>
#include <stack>
using namespace std;

int main() {
    // -----------------------------
    // ✅ Step 1: Create a stack
    // A stack is a LIFO (Last In First Out) data structure.
    // The element inserted last will be removed first.
    // Here we create an empty stack of integers.
    // -----------------------------
    stack<int> s;

    // -----------------------------
    // ✅ Step 2: Push elements into the stack
    // push(x) adds an element to the TOP of the stack.
    // After these insertions:
    // Stack (top → bottom): 40, 30, 20, 10
    // -----------------------------
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // -----------------------------
    // ✅ Step 3: Display and remove all elements
    // top() → returns the topmost element
    // pop() → removes the topmost element
    // The loop continues until stack becomes empty.
    // Since stack follows LIFO, elements will print in reverse order of insertion.
    // -----------------------------
    while(!s.empty()) {
        cout << s.top() << " ";  // Access top element
        s.pop();                 // Remove top element
    }

    cout << endl;  // Print newline after all elements are displayed

    // -----------------------------
    // ✅ Step 4: End of program
    // After popping all elements, the stack becomes empty.
    // -----------------------------
    return 0;
}
