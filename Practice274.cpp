#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;

    // -------------------------------------------
    // Push element into queue
    // -------------------------------------------
    void push(int x) {
        s1.push(x);
    }

    // -------------------------------------------
    // Pop element from queue (front element)
    // -------------------------------------------
    int pop() {
        if (empty()) {
            cout << "Queue is empty! Cannot pop.\n";
            return -1;
        }

        // Move elements from s1 → s2 if needed
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int val = s2.top();
        s2.pop();
        return val;
    }

    // -------------------------------------------
    // Get the front element
    // -------------------------------------------
    int front() {
        if (empty()) {
            cout << "Queue is empty! No front element.\n";
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }

    // -------------------------------------------
    // Check if queue is empty
    // -------------------------------------------
    bool empty() {
        return (s1.empty() && s2.empty());
    }
};

// ==========================================================
// MAIN — Test the MyQueue implementation
// ==========================================================
int main() {

    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front: " << q.front() << endl;   // Expected 10

    cout << "Popped: " << q.pop() << endl;    // Expected 10
    cout << "Front: " << q.front() << endl;   // Expected 20

    q.push(40);
    cout << "Popped: " << q.pop() << endl;    // Expected 20
    cout << "Popped: " << q.pop() << endl;    // Expected 30

    cout << "Front: " << q.front() << endl;   // Expected 40
    cout << "Popped: " << q.pop() << endl;    // Expected 40

    cout << "Is queue empty? " 
         << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
