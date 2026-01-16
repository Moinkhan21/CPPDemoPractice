#include <iostream>
#include <queue>
using namespace std;

int main() {

    // =====================================================
    // MAX HEAP CREATION
    // -----------------------------------------------------
    // By DEFAULT, priority_queue in C++ creates a MAX HEAP.
    //
    // This means:
    //   • The LARGEST element is always at the TOP
    //   • No extra comparator is required
    //
    // Syntax:
    //   priority_queue<int> pq;
    // =====================================================
    priority_queue<int> pq;

    // -----------------------------------------------------
    // Insert elements into the Max Heap
    // -----------------------------------------------------
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    /*
        After inserting elements, heap conceptually looks like:
        (Largest element always on top)

               9
             /   \
            8     6
           / \
          3   4
    */

    // -----------------------------------------------------
    // Access the top (largest) element
    // -----------------------------------------------------
    cout << "Top element: " << pq.top() << endl;  // 9

    // -----------------------------------------------------
    // Remove the top element
    // -----------------------------------------------------
    pq.pop();   // Removes 9

    cout << "Top element: " << pq.top() << endl;  // 8
    pq.pop();

    cout << "Top element: " << pq.top() << endl;  // 6
    pq.pop();

    cout << "Top element: " << pq.top() << endl;  // 4
    pq.pop();

    cout << "Top element: " << pq.top() << endl;  // 3
    pq.pop();

    // -----------------------------------------------------
    // Size of heap after all pops
    // -----------------------------------------------------
    cout << "Size: " << pq.size() << endl;  // 0

    // -----------------------------------------------------
    // Check whether heap is empty
    // -----------------------------------------------------
    if (pq.empty()) {
        cout << "Max heap is empty" << endl;
    }
    else {
        cout << "Max heap is not empty" << endl;
    }

    return 0;
}
