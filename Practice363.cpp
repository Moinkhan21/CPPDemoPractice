#include <iostream>
#include <unordered_map>
using namespace std;

// =====================================================
// PROGRAM: unordered_map Demonstration
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates basic operations of unordered_map.
//
// WHAT IS unordered_map?
//   • A hash table based data structure
//   • Stores data as (key → value) pairs
//   • Provides O(1) average time complexity
//
// COMMON OPERATIONS:
//   insert
//   access
//   search
//   size
//   traversal
//
// DIFFERENCE FROM map:
//   map            → ordered (balanced BST)
//   unordered_map  → unordered (hash table)
// =====================================================
int main() {

    // -------------------------------------------------
    // STEP 1: Creation of unordered_map
    // -------------------------------------------------
    // key   → string
    // value → int
    unordered_map<string, int> m;

    // -------------------------------------------------
    // STEP 2: Insertion Methods
    // -------------------------------------------------

    // Method 1: Using make_pair
    pair<string, int> p = make_pair("Scorpio", 9);
    m.insert(p);

    // Method 2: Direct pair initialization
    pair<string, int> p1("Alto", 2);
    m.insert(p1);

    // Method 3: Using indexing operator
    m["Fortuner"] = 10;

    // -------------------------------------------------
    // STEP 3: Accessing Elements
    // -------------------------------------------------

    // Using at() method
    // Throws exception if key not present
    cout << m.at("Alto") << endl;
    cout << m.at("Scorpio") << endl;

    // Using [] operator
    cout << m["Fortuner"] << endl;

    // -------------------------------------------------
    // STEP 4: Searching Elements
    // -------------------------------------------------

    // count() returns 1 if key exists, otherwise 0
    cout << m.count("Alto") << endl;
    cout << m.count("Innova") << endl;

    // find() returns iterator
    if (m.find("Fortuner") != m.end()) {
        cout << "Fortuner is found" << endl;
    }
    else {
        cout << "Fortuner is not found" << endl;
    }

    // -------------------------------------------------
    // STEP 5: Size of map
    // -------------------------------------------------
    cout << m.size() << endl;

    // -------------------------------------------------
    // STEP 6: Special Case of [] Operator
    // -------------------------------------------------
    // If key does not exist, it creates the key
    // with default value (0 for int)
    cout << m["Hummer"] << endl;

    // Map size increases
    cout << m.size() << endl;

    // -------------------------------------------------
    // STEP 7: Traversing unordered_map
    // -------------------------------------------------
    cout << "Printing all entries: " << endl;

    for (auto i : m) {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}