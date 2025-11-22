#include <iostream>
using namespace std;

class Deque{
    public:
        int *arr;
        int size;
        int front;
        int rear;

        Deque(int size) {
            this -> size = size;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void pushRear(int data) {
            
            //Queue Full
            if((front == 0 && rear == size - 1)) {
                cout << "Q is full, cannot insert" << endl;
                return;
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

        void pushFront(int data) {
            
            //Queue Full
            if((front == 0 && rear == size - 1)) {
                cout << "Q is full, cannot insert" << endl;
                return;
            }
            //Single element case -> first element
            else if(front == -1) {
                front = rear = 0;
                arr[front] = data;
            }
            //Circular nature
            else if(front == 0 && rear != size - 1) {
                front = size - 1;
                arr[front] = data;
            }
            //Normal flow
            else {
                front--;
                arr[front] = data;
            }
        }

        void popFront() {
            //Empty check
            if(front == -1) {
                cout << "Q is empty, cannot pop" << endl;
                return;
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

        void popRear() {
            //Empty check
            if(front == -1) {
                cout << "Q is empty, cannot pop" << endl;
                return;
            }
            //Single element
            else if(front == rear) {
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            //Circular nature
            else if(rear == 0) {
                rear = size - 1;
            }
            //Normal flow
            else {
                rear--;
            }
        }

        void print() {
            for(int i = 0; i < size; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Deque q(10);

    q.pushFront(5);
    q.pushRear(15);
    q.pushFront(25);
    q.pushRear(55);

    // cout << "Size of queue is: " << q.getSize() << endl; 

    q.popFront();
    q.popRear();

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