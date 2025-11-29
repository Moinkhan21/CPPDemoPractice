#include <iostream>
using namespace std;

class KQueue {
public:
    int n, k, freeSpot;
    int *arr, *front, *rear, *next;

    KQueue(int _n, int _k) : n(_n), k(_k), freeSpot(0) {

        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        // Initialize front[] and rear[]
        for (int i = 0; i < k; i++)
            front[i] = rear[i] = -1;

        // Initialize free list
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;

        next[n - 1] = -1;  // last free points to null
    }

    // -------------------------------------------------------
    // PUSH element X into queue qi
    // -------------------------------------------------------
    bool push(int x, int qi) {
        if (freeSpot == -1) {
            cout << "Queue Overflow!\n";
            return false;
        }

        // Step 1: get free index
        int index = freeSpot;

        // Step 2: update freeSpot to next free
        freeSpot = next[index];

        // Step 3: if queue is empty
        if (front[qi] == -1) {
            front[qi] = index;
        } else {
            next[rear[qi]] = index;
        }

        // Step 4: update next[index] and rear, store value
        next[index] = -1;
        rear[qi] = index;
        arr[index] = x;

        return true;
    }

    // -------------------------------------------------------
    // POP from queue qi
    // -------------------------------------------------------
    int pop(int qi) {
        if (front[qi] == -1) {
            cout << "Queue Underflow!\n";
            return -1;
        }

        // Step 1: get index to pop
        int index = front[qi];

        // Step 2: update front
        front[qi] = next[index];

        // Step 3: link popped slot back to free list
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

    ~KQueue() {
        delete[] arr;
        delete[] next;
        delete[] front;
        delete[] rear;
    }
};

int main() {

    KQueue kq(8, 3);

    cout << kq.push(1, 0) << endl;
    cout << kq.push(2, 0) << endl;
    cout << kq.push(5, 1) << endl;
    cout << kq.push(3, 0) << endl;

    cout << "Pop from queue 1: " << kq.pop(1) << endl; // expected 5
    cout << "Pop from queue 0: " << kq.pop(0) << endl; // expected 1

    cout << kq.push(10, 2) << endl;

    cout << "Pop from queue 0: " << kq.pop(0) << endl; // expected 2
    cout << "Pop from queue 2: " << kq.pop(2) << endl; // expected 10

    return 0;
}
