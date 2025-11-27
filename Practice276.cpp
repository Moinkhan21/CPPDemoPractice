#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q;

    // ---------------------------------------
    // Push element onto stack
    // ---------------------------------------
    void push(int x) {
        q.push(x);  // add new element

        // Rotate previous elements behind the new one
        int rotations = q.size() - 1;
        while (rotations--) {
            q.push(q.front());
            q.pop();
        }
    }

    // ---------------------------------------
    // Removes the top element of the stack
    // ---------------------------------------
    int pop() {
        if (q.empty()) {
            cout << "Stack is empty! Cannot pop.\n";
            return -1;
        }
        int topElement = q.front();
        q.pop();
        return topElement;
    }

    // ---------------------------------------
    // Returns top element
    // ---------------------------------------
    int top() {
        if (q.empty()) {
            cout << "Stack is empty! No top element.\n";
            return -1;
        }
        return q.front();
    }

    // ---------------------------------------
    // Returns whether stack is empty
    // ---------------------------------------
    bool empty() {
        return q.empty();
    }
};

// ======================================================
// MAIN — Test stack implementation
// ======================================================
int main() {

    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.top() << endl;      // Expected 30
    cout << "Pop: " << st.pop() << endl;      // Expected 30
    cout << "Top: " << st.top() << endl;      // Expected 20

    st.push(40);
    cout << "Top: " << st.top() << endl;      // Expected 40

    cout << "Pop: " << st.pop() << endl;      // Expected 40
    cout << "Pop: " << st.pop() << endl;      // Expected 20
    cout << "Pop: " << st.pop() << endl;      // Expected 10

    cout << "Is empty? " 
         << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}
