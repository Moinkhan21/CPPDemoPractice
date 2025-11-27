#include <iostream>
#include <deque>
using namespace std;

int main() {

    // =====================================================================
    // Creation of a DEQUE (Double Ended Queue)
    // ---------------------------------------------------------------------
    // A deque allows insertion and deletion from BOTH ends:
    //   • push_front() → insert at beginning
    //   • push_back()  → insert at end
    //   • pop_front()  → remove from beginning
    //   • pop_back()   → remove from end
    //
    // Internally, deque uses a dynamic segmented array, making operations
    // efficient and fast from both sides.
    // =====================================================================
    deque<int> dq;

    // ---------------------------------------------------------------------
    // INSERTION OPERATIONS
    // ---------------------------------------------------------------------

    dq.push_front(5);   // Insert 5 at the front → dq = [5]
    dq.push_front(10);  // Insert 10 at the front → dq = [10, 5]
    dq.push_back(20);   // Insert 20 at the back  → dq = [10, 5, 20]
    dq.push_back(30);   // Insert 30 at the back  → dq = [10, 5, 20, 30]

    // ---------------------------------------------------------------------
    // SIZE CHECK — returns current number of elements
    // ---------------------------------------------------------------------
    cout << "Size: " << dq.size() << endl;   // Output: 4

    // ---------------------------------------------------------------------
    // REMOVAL OPERATIONS
    // ---------------------------------------------------------------------

    dq.pop_front();     // Remove element from front → removes 10
                        // dq becomes [5, 20, 30]

    cout << "Size: " << dq.size() << endl;   // Output: 3

    dq.pop_back();      // Remove element from back → removes 30
                        // dq becomes [5, 20]

    cout << "Size: " << dq.size() << endl;   // Output: 2

    // ---------------------------------------------------------------------
    // ACCESS FRONT & BACK ELEMENTS
    // ---------------------------------------------------------------------
    // front() → returns first element
    // back()  → returns last element
    // ---------------------------------------------------------------------

    cout << "Front: " << dq.front() << endl; // Output: 5
    cout << "Back: "  << dq.back()  << endl; // Output: 20

    return 0;
}
