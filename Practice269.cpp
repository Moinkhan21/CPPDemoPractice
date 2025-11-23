 #include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseKElements(queue<int> &q, int k) {

    //Step A: queue -> K elements -> Stack
    stack<int> s;
    int count = 0;
    int n = q.size();

    if(k <= 0 || k > n)
        return;

    while(!q.empty()) {
        int temp = q.front();
        q.pop();
        s.push(temp);
        count++;

        if(count == k)
            break;
    }

    //Step B: s -> q me wapas
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        q.push(temp);
    }

    //Step C: push n - k element from q front to back
    count = 0;
    while(!q.empty() && n - k != 0) {
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;

        if(count == n - k)
            break;
    }

}

int main() {
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseKElements(q, 3);

    cout << "Printing Queue with reverse K elements: " << endl;
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}