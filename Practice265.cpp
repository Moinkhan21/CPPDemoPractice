#include <iostream>
using namespace std;

// ============================================================================
// CLASS: Deque (Double-Ended Queue Implementation using Circular Array)
// ----------------------------------------------------------------------------
// A Deque allows insertion and deletion from BOTH ends — front and rear.
// This implementation uses circular index movement to efficiently reuse space.
// ----------------------------------------------------------------------------
// Key Variables:
//   • arr   → dynamic array to store elements
//   • size  → capacity of deque
//   • front → index of first valid element
//   • rear  → index of last valid element
// ----------------------------------------------------------------------------
// Initial State:
//   • front = rear = -1  → queue is empty
// ============================================================================
class Deque {
public:
    int *arr;
    int size;
    int front;
    int rear;

    // ------------------------------------------------------------------------
    // CONSTRUCTOR — allocate memory and initialize pointers
    // ------------------------------------------------------------------------
    Deque(int size) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // ------------------------------------------------------------------------
    // FUNCTION: pushRear(int data)
    // Inserts an element at the REAR end of the deque
    // ------------------------------------------------------------------------
    void pushRear(int data) {

        // CASE 1: Queue is FULL
        // Simplified condition → when front is at 0 and rear at last index
        if ((front == 0 && rear == size - 1)) {
            cout << "Q is full, cannot insert" << endl;
            return;
        }

        // CASE 2: Queue EMPTY → first insertion
        else if (front == -1) {
            front = rear = 0;
            arr[rear] = data;
        }

        // CASE 3: Circular INSERTION at rear end
        else if (rear == size - 1 && front != 0) {
            rear = 0;          // wrap rear pointer
            arr[rear] = data;
        }

        // CASE 4: Normal insertion
        else {
            rear++;
            arr[rear] = data;
        }
    }

    // ------------------------------------------------------------------------
    // FUNCTION: pushFront(int data)
    // Inserts an element at the FRONT end of the deque
    // ------------------------------------------------------------------------
    void pushFront(int data) {

        // CASE 1: Queue FULL
        if ((front == 0 && rear == size - 1)) {
            cout << "Q is full, cannot insert" << endl;
            return;
        }

        // CASE 2: Queue EMPTY → first element inserted
        else if (front == -1) {
            front = rear = 0;
            arr[front] = data;
        }

        // CASE 3: Circular INSERTION at front
        else if (front == 0 && rear != size - 1) {
            front = size - 1;
            arr[front] = data;
        }

        // CASE 4: Normal front insertion
        else {
            front--;
            arr[front] = data;
        }
    }

    // ------------------------------------------------------------------------
    // FUNCTION: popFront()
    // Removes element from the FRONT of the deque
    // ------------------------------------------------------------------------
    void popFront() {

        // CASE 1: Queue EMPTY
        if (front == -1) {
            cout << "Q is empty, cannot pop" << endl;
            return;
        }

        // CASE 2: Single element → becomes empty after popping
        else if (front == rear) {
            arr[front] = -1;
            front = rear = -1;
        }

        // CASE 3: Circular wrap — front moves to start
        else if (front == size - 1) {
            front = 0;
        }

        // CASE 4: Normal increment of front
        else {
            front++;
        }
    }

    // ------------------------------------------------------------------------
    // FUNCTION: popRear()
    // Removes element from the REAR of the deque
    // ------------------------------------------------------------------------
    void popRear() {

        // CASE 1: Empty deque
        if (front == -1) {
            cout << "Q is empty, cannot pop" << endl;
            return;
        }

        // CASE 2: Single element removal
        else if (front == rear) {
            arr[front] = -1;
            front = rear = -1;
        }

        // CASE 3: Circular movement when rear at index 0
        else if (rear == 0) {
            rear = size - 1;
        }

        // CASE 4: Normal decrement
        else {
            rear--;
        }
    }

    // ------------------------------------------------------------------------
    // FUNCTION: print()
    // Prints the entire underlying array (for debugging purposes)
    // (Not an actual deque traversal; only shows memory layout)
    // ------------------------------------------------------------------------
    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// ============================================================================
// MAIN — Testing the Deque Implementation
// ============================================================================
int main() {
    Deque q(10);

    q.pushFront(5);
    q.pushRear(15);
    q.pushFront(25);
    q.pushRear(55);

    q.popFront();
    q.popRear();

    return 0;
}
