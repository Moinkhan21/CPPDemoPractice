#include <iostream>
#include <deque>
using namespace std;

int main() {

    //Creation
    deque<int> dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_back(30);

    cout << "Size: " << dq.size() << endl;

    dq.pop_front();
    cout << "Size: " << dq.size() << endl;

    dq.pop_back();
    cout << "Size: " << dq.size() << endl;

    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() << endl;

    return 0;
}