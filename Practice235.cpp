#include <iostream>
using namespace std;

class Stack {

    public:
        int *arr;   // Dynamic array to store stack elements
        int top;    // Index of top element
        int size;   // Total capacity of stack

        // ---------------------------------------------
        // ✅ Constructor to initialize stack
        // Creates a dynamic array of given 'size'
        // Sets top to -1, meaning stack is initially empty.
        // ---------------------------------------------
        Stack(int size) {
            arr = new int[size];   // allocate memory dynamically
            this -> size = size;   // store stack capacity
            top = -1;              // initialize top as empty
        }

        // ---------------------------------------------
        // ✅ push(data): Insert an element into the stack
        // Conditions:
        //   - If there’s space (top < size - 1), insert element
        //   - Else, stack overflow (cannot insert)
        // ---------------------------------------------
        void push(int data) {
            if(size - top > 1) {        // check if there’s space left
                top++;                  // move top pointer
                arr[top] = data;        // insert element
            }
            else {
                cout << "Stack overflow..." << endl;  // no space left
            }
        }

        // ---------------------------------------------
        // ✅ pop(): Removes top element from the stack
        // Conditions:
        //   - If stack is empty (top == -1), underflow error
        //   - Else, decrease top index (effectively remove element)
        // ---------------------------------------------
        void pop() {
            if(top == -1) {
                cout << "Stack underflow, can't delete element" << endl;
            }
            else {
                top--; // remove element logically by moving top
            }
        }

        // ---------------------------------------------
        // ✅ getTop(): Returns element at the top of stack
        // Conditions:
        //   - If stack is empty, print message and return 0 (optional)
        //   - Else, return arr[top]
        // ---------------------------------------------
        int getTop() {
            if(top == -1) {
                cout << "There is no element in Stack" << endl;
                return 0;  // safe return value if stack empty
            }
            else {
                return arr[top];
            }
        }

        // ---------------------------------------------
        // ✅ getSize(): Returns current number of elements in stack
        // Formula: top + 1
        // ---------------------------------------------
        int getSize() {
            return top + 1;
        }

        // ---------------------------------------------
        // ✅ isEmpty(): Checks whether stack is empty or not
        // Returns true if empty, else false
        // ---------------------------------------------
        bool isEmpty() {
            if(top == -1) {
                return true;
            }
            else{
                return false;
            }
        }
};

// ---------------------------------------------
// ✅ main() function to demonstrate Stack operations
// ---------------------------------------------
int main() {

    Stack s(10);  // Create a stack of capacity 10

    //Insertion
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    // Display all elements in LIFO order using getTop() + pop()
    while(!s.isEmpty()) {
        cout << s.getTop() << " ";  // print top element
        s.pop();                    // remove it
    }
    cout << endl;

    // Display stack size after removing all elements
    cout << "Size of stack " << s.getSize() << endl;
    
    // Attempt another pop to show underflow handling
    s.pop();

    return 0;
}
