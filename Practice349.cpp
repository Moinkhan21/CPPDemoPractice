#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// ===============================
// Node Structure
// ===============================
class node {
public:
    int data;
    int row;
    int col;

    node(int d, int r, int c) {
        data = d;
        row = r;
        col = c;
    }
};

// ===============================
// Min Heap Comparator
// ===============================
class compare {
public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;   // min-heap
    }
};

// ===============================
// Smallest Range Function
// ===============================
vector<int> smallestRange(vector<vector<int>>& nums) {

    int mini = INT_MAX;
    int maxi = INT_MIN;

    priority_queue<node*, vector<node*>, compare> minHeap;

    int k = nums.size();

    // Initial insertion
    for (int i = 0; i < k; i++) {
        int element = nums[i][0];
        maxi = max(maxi, element);
        mini = min(mini, element);
        minHeap.push(new node(element, i, 0));
    }

    int ansStart = mini;
    int ansEnd = maxi;

    while (!minHeap.empty()) {

        node* top = minHeap.top();
        minHeap.pop();

        int topelement = top->data;
        int topRow = top->row;
        int topCol = top->col;

        // Update mini
        mini = topelement;

        // Check range
        int currRange = maxi - mini;
        int ansRange = ansEnd - ansStart;

        if (currRange < ansRange) {
            ansStart = mini;
            ansEnd = maxi;
        }

        // Push next element from same list
        if (topCol + 1 < nums[topRow].size()) {
            int nextVal = nums[topRow][topCol + 1];
            maxi = max(maxi, nextVal);
            minHeap.push(new node(nextVal, topRow, topCol + 1));
        }
        else {
            break;  // One list exhausted
        }
    }

    return {ansStart, ansEnd};
}

// ===============================
// MAIN FUNCTION
// ===============================
int main() {

    /*
        Input:
        [
          [4, 10, 15, 24, 26],
          [0, 9, 12, 20],
          [5, 18, 22, 30]
        ]

        Output:
        Smallest Range = [20, 24]
    */

    vector<vector<int>> nums = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };

    vector<int> result = smallestRange(nums);

    cout << "Smallest Range is: ["
         << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}
