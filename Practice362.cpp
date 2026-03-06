#include <iostream>
#include <unordered_map>
using namespace std;

// =====================================================
// PROGRAM: unordered_map Basic Operations
// -----------------------------------------------------
// PURPOSE:
//   Demonstrates how to use unordered_map in C++.
//
// WHAT IS unordered_map?
//   • A hash table based container
//   • Stores elements in (key → value) format
//   • Keys are unique
//
// ADVANTAGE:
//   • Average time complexity for insert/search
//     is O(1)
//
// NOTE:
//   unordered_map does NOT maintain order
// =====================================================
int main() {

    // -------------------------------------------------
    // STEP 1: Creation of unordered_map
    // -------------------------------------------------
    // key   → string
    // value → int
    unordered_map<string, int> m;

    // -------------------------------------------------
    // STEP 2: Insertion into unordered_map
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
    // STEP 3: Accessing elements
    // -------------------------------------------------

    // at() method → throws exception if key not present
    cout << m.at("Alto") << endl;
    cout << m.at("Scorpio") << endl;

    // [] operator → accesses value
    cout << m["Fortuner"] << endl;

    // -------------------------------------------------
    // STEP 4: Searching elements
    // -------------------------------------------------

    // count() returns:
    // 1 → if key exists
    // 0 → if key does not exist
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
    // STEP 5: Size of unordered_map
    // -------------------------------------------------
    cout << m.size() << endl;

    // -------------------------------------------------
    // STEP 6: Special case of [] operator
    // -------------------------------------------------
    // If key does not exist,
    // unordered_map creates it with default value
    // For int → default value = 0

    cout << m["Hummer"] << endl;

    // Map size increases because new key created
    cout << m.size() << endl;

    return 0;
}