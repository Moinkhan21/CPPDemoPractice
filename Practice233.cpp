#include <iostream>
#include <stack>
using namespace std;

int main() {

    //Creation 
    // A stack is a container adapter that follows LIFO (Last In First Out) order.
    // Here, we create an empty stack of integers using STL.
    stack<int> st;

    //Insertion
    // push() adds elements to the TOP of the stack.
    st.push(10);   // Stack: [10]
    st.push(20);   // Stack: [10, 20]
    st.push(30);   // Stack: [10, 20, 30]
    st.push(40);   // Stack: [10, 20, 30, 40]

    //Remove
    // pop() removes the element from the TOP of the stack.
    // After this operation, 40 will be removed.
    st.pop();      // Stack now becomes: [10, 20, 30]

    //Check element on top
    // top() returns the topmost element of the stack without removing it.
    cout << "Element on top is: " << st.top() << endl; // Expected: 30

    //Size
    // size() returns the number of elements currently present in the stack.
    cout << "Size of stack is: " << st.size() << endl; // Expected: 3

    // empty() checks if the stack is empty.
    // It returns true (1) if empty, false (0) otherwise.
    if(st.empty()) 
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    return 0;
}
