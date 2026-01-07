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

    // ===============================
    // INSERT INTO MAX HEAP
    // ===============================
    void insert(int value) {

        int index = ++size;
        arr[index] = value;

        // SIFT UP
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

    // ===============================
    // DELETE ROOT FROM MAX HEAP
    // ===============================
    int deleteFromHeap() {

        if (size == 0) {
            cout << "Heap is empty\n";
            return -1;
        }

        int ans = arr[1];

        // Replace root with last element
        arr[1] = arr[size];
        size--;

        // SIFT DOWN
        int index = 1;
        while (index <= size) {

            int left = 2 * index;
            int right = 2 * index + 1;
            int largest = index;

            if (left <= size && arr[largest] < arr[left]) {
                largest = left;
            }
            if (right <= size && arr[largest] < arr[right]) {
                largest = right;
            }

            if (largest == index) {
                break;
            }
            else {
                swap(arr[index], arr[largest]);
                index = largest;
            }
        }
        return ans;
    }
};

int main() {

    Heap h;

    // Sentinel assumption
    h.arr[0] = -1;

    // Pre-filled heap
    h.arr[1] = 100;
    h.arr[2] = 50;
    h.arr[3] = 60;
    h.arr[4] = 40;
    h.arr[5] = 45;
    h.size = 5;

    cout << "Initial Heap:\n";
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    // Insert
    h.insert(110);

    cout << "\nHeap after insert:\n";
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    // Delete root
    int deleted = h.deleteFromHeap();
    cout << "\nDeleted element: " << deleted << endl;

    cout << "\nHeap after delete:\n";
    for (int i = 0; i <= h.size; i++) {
        cout << h.arr[i] << " ";
    }
    cout << endl;

    return 0;
}
