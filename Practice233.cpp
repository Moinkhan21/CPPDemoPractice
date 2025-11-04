#include <iostream>
#include <stack>
using namespace std;

int main() {

    //Creation 
    stack<int> st;

    //Insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    //Remove
    st.pop();

    //Check element on top
    cout << "Element on top is: " << st.top() << endl;

    //Size
    cout << "size of stack is: " << st.size() << endl;

    if(st.empty()) 
        cout << "Stack is empty" << endl;
    else
        cout << "Stack is not empty" << endl;

    return 0;
}