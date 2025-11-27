#include <iostream>
using namespace std;

// ============================================================================
// CLASS: Queue (Linear Queue Implementation using Array)
// ----------------------------------------------------------------------------
// This class implements a simple **linear queue** using an array.
// Key characteristics:
//   - `front`  → index of current front element
//   - `rear`   → index where next element will be inserted
//   - Queue grows linearly; not circular.
//   - When queue becomes empty again, both pointers are reset to 0.
// ============================================================================
class Queue {
public:
    int *arr;     // Dynamic array for storing queue elements
    int size;     // Maximum capacity of queue
    int front;    // Points to first valid element
    int rear;     // Points to next insertion index

    // ------------------------------------------------------------------------
    // CONSTRUCTOR
    // Initializes queue with given size, allocates array, sets pointers to 0
    // ------------------------------------------------------------------------
    Queue(int size) {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // ------------------------------------------------------------------------
    // FUNCTION: push(int data)
    // Inserts an element at the rear of the queue (if space is available)
    // ------------------------------------------------------------------------
    void push(int data) {
        // Full queue check (linear queue → no wrap-around)
        if (rear == size) {
            cout << "Q is full" << endl;
        }
        else {
            arr[rear] = data;  // Insert element
            rear++;            // Move rear forward
        }
    }

    // ------------------------------------------------------------------------
    // FUNCTION: pop()
    // Removes the front element from the queue
    // ------------------------------------------------------------------------
    void pop() {
        // If front == rear ⇒ queue is empty
        if (front == rear) {
            cout << "Q is empty" << endl;
        }
        else {
            arr[front] = -1;  // Optional: mark as removed
            front++;          // Move front forward

            // If queue becomes empty after pop, reset pointers
            if (front == rear) {
                front = 0;
                rear = 0;
            }
        }
    }

    // ------------------------------------------------------------------------
    // FUNCTION: getFront()
    // Returns the element at the front of the queue
    // ------------------------------------------------------------------------
    int getFront() {
        if (front == rear) {
            cout << "Q is empty" << endl;
        }
        else {
            return arr[front];
        }
        return -1; // Return invalid value after warning
    }

    // ------------------------------------------------------------------------
    // FUNCTION: isEmpty()
    // Checks whether queue is empty
    // ------------------------------------------------------------------------
    bool isEmpty() {
        return (front == rear);
    }

    // ------------------------------------------------------------------------
    // FUNCTION: getSize()
    // Returns the number of valid elements present in the queue
    // ------------------------------------------------------------------------
    int getSize() {
        return rear - front;
    }
};

// ============================================================================
// MAIN FUNCTION — Testing the Queue Implementation
// ============================================================================
int main() {
    Queue q(10);   // Create queue of size 10

    // Insert elements
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    cout << "Size of queue is: " << q.getSize() << endl; 

    // Remove front element
    q.pop();

    cout << "Size of queue is: " << q.getSize() << endl;

    // Display front element
    cout << "Front element is: " << q.getFront() << endl;

    // Check if queue is empty
    if (q.isEmpty()) {
        cout << "Q is empty" << endl;
    }
    else {
        cout << "Q is not empty" << endl;
    }

    return 0;
}
