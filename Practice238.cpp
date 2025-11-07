#include <iostream>
#include <stack>
using namespace std;

// ========================================================
// ✅ Function: printMiddle
// Purpose: Prints the middle element of the stack using recursion.
// ========================================================
// Concept:
// - We use recursion to temporarily pop elements from the stack until
//   we reach the middle one.
// - Then we print the middle element.
// - During backtracking, we push all elements back to restore the stack.
// ========================================================
void printMiddle(stack<int> &s, int &totalSize) {

    // -----------------------------------------
    // ✅ Step 1: Base case - Handle empty stack
    // -----------------------------------------
    if(s.size() == 0) {
        cout << "There is no element in stack" << endl;
        return;
    }

    // -----------------------------------------
    // ✅ Step 2: Base case - When middle element is reached
    // Logic:
    //   totalSize/2 gives half the size (0-based)
    //   +1 ensures we reach the middle (1-based indexing)
    // Example: For 7 elements, totalSize/2 = 3 → middle = 4th element
    // -----------------------------------------
    if(s.size() == totalSize/2 + 1) {
        cout << "Middle element is: " << s.top() << endl;
        return;
    }

    // -----------------------------------------
    // ✅ Step 3: Store the top element temporarily
    // We’ll remove it and later restore during backtracking.
    // -----------------------------------------
    int temp = s.top();
    s.pop();

    // -----------------------------------------
    // ✅ Step 4: Recursive call to reach middle
    // Each recursive call pops one element and reduces the stack size.
    // Eventually, when size == totalSize/2 + 1, the middle is printed.
    // -----------------------------------------
    printMiddle(s, totalSize);

    // -----------------------------------------
    // ✅ Step 5: Backtracking step
    // Push all removed elements back to restore original stack.
    // -----------------------------------------
    s.push(temp);
}

// ========================================================
// ✅ MAIN FUNCTION — Demonstrating the logic
// ========================================================
// Steps:
// 1. Create and fill a stack.
// 2. Call printMiddle() to print the middle element.
// 3. The stack remains unchanged after function call.
// ========================================================
int main() {
    stack<int> s;

    // Pushing elements into the stack
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    // totalSize stores original number of elements
    int totalSize = s.size();

    // Function call to find and print middle element
    printMiddle(s, totalSize);

    return 0;
}
