#include <iostream>
#include <queue>
using namespace std;

int main() {

    // =====================================================
    // MIN HEAP CREATION
    // -----------------------------------------------------
    // priority_queue by default creates a MAX HEAP.
    //
    // To create a MIN HEAP, we use:
    //   priority_queue<int, vector<int>, greater<int>>
    //
    // Here:
    //   • int            → type of elements
    //   • vector<int>    → underlying container
    //   • greater<int>   → comparator (smallest element on top)
    // =====================================================
    priority_queue<int, vector<int>, greater<int>> pq;

    // -----------------------------------------------------
    // Insert elements into the Min Heap
    // -----------------------------------------------------
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    /*
        After inserting elements, heap structure conceptually is:
        (Smallest element always on top)

              3
            /   \
           4     6
          / \
         9   8
    */

    // -----------------------------------------------------
    // Access the top (smallest) element
    // -----------------------------------------------------
    cout << "Top element: " << pq.top() << endl;  // 3

    // -----------------------------------------------------
    // Remove the top element
    // -----------------------------------------------------
    pq.pop();   // Removes 3

    // -----------------------------------------------------
    // Current size of heap
    // -----------------------------------------------------
    cout << "Size: " << pq.size() << endl;

    // -----------------------------------------------------
    // Repeatedly check top and pop
    // -----------------------------------------------------
    cout << "Top element: " << pq.top() << endl;  // 4
    pq.pop();

    cout << "Top element: " << pq.top() << endl;  // 6
    pq.pop();

    cout << "Top element: " << pq.top() << endl;  // 8
    pq.pop();

    cout << "Top element: " << pq.top() << endl;  // 9
    pq.pop();

    // -----------------------------------------------------
    // Check whether heap is empty
    // -----------------------------------------------------
    if (pq.empty()) {
        cout << "Min heap is empty" << endl;
    }
    else {
        cout << "Min heap is not empty" << endl;
    }

    return 0;
}
