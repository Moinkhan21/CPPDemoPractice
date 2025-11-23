#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueueRecursion(queue<int> & q) {
    //Base case
    if(q.empty()) 
        return;

    //Step A
    int temp = q.front();
    q.pop();

    //Step B
    reverseQueueRecursion(q);

    //StepC
    q.push(temp);
}

int main() {
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseQueueRecursion(q);

    cout << "Printing Queue" << endl;
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}