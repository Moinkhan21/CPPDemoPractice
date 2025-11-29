// =====================================================================
// CLASS: KQueue  (k queues in a single array)
// ---------------------------------------------------------------------
// PURPOSE:
//   Efficiently implement *k independent queues* using a *single array*
//   of size 'n'. Supports push() and pop() in O(1) time.
//
// WHY THIS IS NEEDED?
//   Creating separate arrays for each queue wastes memory.
//   Using a single array allows multiple queues to share space dynamically.
//
// CORE IDEA:
//   Use 4 arrays:
//     • arr[]   → stores actual values
//     • front[] → stores front index of each queue
//     • rear[]  → stores rear index of each queue
//     • next[]  → works like a linked list:
//           - For free slots → next[i] = next free index
//           - For queue nodes → next[i] = next element in that queue
//
//   A variable `freeSpot` always tells where the next free index is.
//
// WORKING OF PUSH(x, qi):
//     1. Take a free index from freeSpot
//     2. Update freeSpot to next free location
//     3. Insert element in arr[]
//     4. Update queue links using next[] and rear[]
//
// WORKING OF POP(qi):
//     1. Remove element at front[qi]
//     2. Move front pointer to next element
//     3. Add the freed index back to free list
//
// COMPLEXITY:
//     Push: O(1)
//     Pop:  O(1)
//     Space: O(n + k)
// =====================================================================

#include <iostream>
using namespace std;

class KQueue {
public:
    int n, k, freeSpot; 
    // n  → total size of array
    // k  → number of queues
    // freeSpot → index of the first free position in array

    int *arr, *front, *rear, *next;
    // arr[]   → stores actual values
    // front[] → stores front index of each queue
    // rear[]  → stores rear index of each queue
    // next[]  → maintains next free slot OR next element link

    // ===================================================
    // CONSTRUCTOR — initializes k queues inside size n
    // ===================================================
    KQueue(int _n, int _k) : n(_n), k(_k), freeSpot(0) {

        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];

        // -------------------------------
        // Initialize all queues as empty
        // -------------------------------
        for (int i = 0; i < k; i++)
            front[i] = rear[i] = -1;

        // -------------------------------
        // Build "free list" in next[]
        // next[i] = next free index
        // -------------------------------
        for (int i = 0; i < n - 1; i++)
            next[i] = i + 1;

        next[n - 1] = -1;  // last index points to NONE
    }

    // ===================================================
    // PUSH element X into queue number qi (0-based index)
    // ===================================================
    bool push(int x, int qi) {

        // No free space
        if (freeSpot == -1) {
            cout << "Queue Overflow!\n";
            return false;
        }

        // 1️⃣ Pick free index
        int index = freeSpot;

        // 2️⃣ Move freeSpot to next available slot
        freeSpot = next[index];

        // 3️⃣ If queue qi is empty → index becomes front
        if (front[qi] == -1) {
            front[qi] = index;
        } 
        else {
            // Link previous rear to new index
            next[rear[qi]] = index;
        }

        // 4️⃣ Update next[index] because it's last element now
        next[index] = -1;

        // 5️⃣ Update rear pointer
        rear[qi] = index;

        // 6️⃣ Store value
        arr[index] = x;

        return true;
    }

    // ===================================================
    // POP element from queue number qi (0-based index)
    // ===================================================
    int pop(int qi) {

        // Underflow condition → queue empty
        if (front[qi] == -1) {
            cout << "Queue Underflow!\n";
            return -1;
        }

        // 1️⃣ Index to remove
        int index = front[qi];

        // 2️⃣ Move front to next element in that queue
        front[qi] = next[index];

        // 3️⃣ Mark this index as free — link it back to free list
        next[index] = freeSpot;
        freeSpot = index;

        // 4️⃣ Return popped value
        return arr[index];
    }

    // Destructor to free memory
    ~KQueue() {
        delete[] arr;
        delete[] next;
        delete[] front;
        delete[] rear;
    }
};

// ===================================================
// MAIN — TESTING KQueue
// ===================================================
int main() {

    KQueue kq(8, 3);   // 3 queues inside an array of size 8

    cout << kq.push(1, 0) << endl;  // push into queue 0
    cout << kq.push(2, 0) << endl;  
    cout << kq.push(5, 1) << endl;  // push into queue 1
    cout << kq.push(3, 0) << endl;

    cout << "Pop from queue 1: " << kq.pop(1) << endl; // expected 5
    cout << "Pop from queue 0: " << kq.pop(0) << endl; // expected 1

    cout << kq.push(10, 2) << endl; // push into queue 2

    cout << "Pop from queue 0: " << kq.pop(0) << endl; // expected 2
    cout << "Pop from queue 2: " << kq.pop(2) << endl; // expected 10

    return 0;
}
