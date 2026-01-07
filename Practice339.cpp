#include <iostream>
#include <algorithm>
using namespace std;

class Heap {
public:
    int arr[101];
    int size;

    Heap() {
        size = 0;
    }

    void insert(int value) {

        int index = ++size;
        arr[index] = value;

        // ===== LOGIC KEPT SAME — SIFT UP =====
        while (index > 1) {

            int parentIndex = index / 2;

            if (arr[index] > arr[parentIndex]) {
                swap(arr[index], arr[parentIndex]);
                index = parentIndex;
            }
            else {
                break;
            }
        }
    }
};

int main() {

    Heap h;

    // Sentinel assumption (as per your logic)
    h.arr[0] = -1;

    // Pre-filled heap assumption
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;

    cout << "Printing the heap " << endl;
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    // Insert new value
    h.insert(110);

    cout << "\nPrinting the heap after insert" << endl;
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    return 0;
}
