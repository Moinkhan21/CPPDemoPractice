#include <iostream>
#include <queue>
using namespace std;

int main() {
    //Min-heap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "Size: " << pq.size() << endl;
    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "Top element: " << pq.top() << endl;
    pq.pop();
    cout << "Top element: " << pq.top() << endl;
    pq.pop();
   
    if(pq.empty()) {
        cout << "Min heap is empty " << endl;
    }
    else {
        cout << "Min heap is not empty " << endl;
    }

    return 0;
}