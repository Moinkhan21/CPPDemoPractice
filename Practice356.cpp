#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    void heapify(vector<int>& v, int i, int n) {
        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int swapindex = i;

            if (left < n && v[left] > v[swapindex]) {
                swapindex = left;
            }
            if (right < n && v[right] > v[swapindex]) {
                swapindex = right;
            }
            if (swapindex == i) {
                break;
            }
            swap(v[i], v[swapindex]);
            i = swapindex;
        }
    }

    vector<int> mergeHeaps(vector<int>* a, vector<int>& b, int n, int m) {

        // 1. Merge both heaps
        vector<int> c(a->begin(), a->end());
        c.insert(c.end(), b.begin(), b.end());

        // 2. Heapify the merged vector
        for (int i = (c.size() / 2) - 1; i >= 0; --i) {
            heapify(c, i, c.size());
        }
        return c;
    }
};

int main() {

    // First max heap
    vector<int> a = {10, 5, 6, 2};

    // Second max heap
    vector<int> b = {12, 7, 9};

    Solution sol;

    vector<int> mergedHeap = sol.mergeHeaps(&a, b, a.size(), b.size());

    cout << "Merged Max Heap: ";
    for (int x : mergedHeap) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
