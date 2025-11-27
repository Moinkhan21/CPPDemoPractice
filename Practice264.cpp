#include <iostream>
using namespace std;

// ============================================================================
// CLASS: CirQueue (Circular Queue Implementation using Array)
// ----------------------------------------------------------------------------
// A circular queue efficiently reuses empty space by wrapping indices using
// circular movement. Instead of shifting elements, pointers rotate within array.
// ----------------------------------------------------------------------------
// Key details:
//   • `front` → index of first valid element
//   • `rear`  → index of last valid element
//   • Both initialized to -1 → queue is empty
//   • Circular movement occurs when pointer reaches end of array
// ============================================================================
class CirQueue {
public:
    int size;   // Maximum capacity of the queue
    int *arr;   // Dynamic array for storage
    int front;  // Points to first element
    int rear;   // Points to last element

    // ------------------------------------------------------------------------
    // CONSTRUCTOR — initializes circular queue
    // ------------------------------------------------------------------------
    CirQueue(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // ------------------------------------------------------------------------
    // FUNCTION: push(int data)
    // Inserts an element into the circular queue
    // ------------------------------------------------------------------------
    void push(int data) {

        // CASE 1: Queue is full
        // Conditions:
        //   • front == 0 and rear == size-1   (rear at end, front at start)
        //   • OR (not checked here) front == rear+1 (wrap-around full condition)
        if ((front == 0 && rear == size - 1)) {
            cout << "Q is full, cannot insert" << endl;
        }

        // CASE 2: Queue is completely empty (first insertion)
        else if (front == -1) {
            front = rear = 0;        // First element added
            arr[rear] = data;
        }

        // CASE 3: Circular wrap — rear at end but front not at start
        // Meaning: spots at beginning of array available
        else if (rear == size - 1 && front != 0) {
            rear = 0;                // wrap rear to start
            arr[rear] = data;
        }

        // CASE 4: Normal insertion — simply increment rear
        else {
            rear++;
            arr[rear] = data;
        }
    }

    // ------------------------------------------------------------------------
    // FUNCTION: pop()
    // Removes the front element from the queue
    // ------------------------------------------------------------------------
    void pop() {

        // CASE 1: Empty queue
        if (front == -1) {
            cout << "Q is empty, cannot pop" << endl;
        }

        // CASE 2: Single element exists → popping makes queue empty
        else if (front == rear) {
            arr[front] = -1;  // optional clearing
            front = rear = -1;
        }

        // CASE 3: Circular movement — front reaches end, wrap to beginning
        else if (front == size - 1) {
            front = 0;
        }

        // CASE 4: Normal pop — just increment front
        else {
            front++;
        }
    }
};

// ============================================================================
// MAIN — Basic Testing of Circular Queue
// ============================================================================
int main() {
    CirQueue q(10);  // Circular queue of size 10

    // Insert few elements
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    // Remove one element
    q.pop();

    return 0;
}
