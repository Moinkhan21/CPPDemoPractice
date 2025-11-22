#include <iostream>
using namespace std;

class CirQueue {
    public:
        int size;
        int *arr;
        int front;
        int rear;

        CirQueue(int size) {
            this -> size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void push(int data) {
            
            //Queue Full
            if((front == 0 && rear == size - 1)) {
                cout << "Q is full, cannot insert" << endl;
            }
            //Single element case -> first element
            else if(front == -1) {
                front = rear = 0;
                arr[rear] = data;
            }
            //Circular nature
            else if(rear == size - 1 && front != 0) {
                rear = 0;
                arr[rear] = data;
            }
            //Normal flow
            else {
                rear++;
                arr[rear] = data;
            }
        }

        void pop() {
            //Empty check
            if(front == -1) {
                cout << "Q is empty, cannot pop" << endl;
            }
            //Single element
            else if(front == rear) {
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            //Circular nature
            else if(front == size - 1) {
                front = 0;
            }
            //Normal flow
            else {
                front++;
            }
        }
};

int main() {
    CirQueue q(10);

    q.push(5);
    q.push(15);
    q.push(25);
    q.push(55);

    // cout << "Size of queue is: " << q.getSize() << endl; 

    q.pop();

    // cout << "Size of queue is: " << q.getSize() << endl;

    // cout << "Front element is: " << q.getFront() << endl;

    // if(q.isEmpty()){
    //     cout << "Q is empty" << endl;
    // }
    // else{
    //     cout << "Q is not empty" << endl;
    // }

    return 0;
}