#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void print(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

void sortZeroOneTwo(Node* &head) {
    //Step 1: Find count of zeroes, ones and twos
    int zero = 0;
    int one = 0;
    int two = 0;

    Node* temp = head;
    while(temp != NULL) {
        if(temp -> data == 0)
            zero++;
        else if(temp -> data == 1)
            one++;
        else if(temp -> data == 2)
            two++;
        temp = temp -> next;
    }

    //Step 2: fill zeroes, ones and twos in the original
    temp = head;
    while(temp != NULL) {
        //Fill zeroes
        while (zero--)
        {
            temp -> data = 0;
            temp = temp -> next;
        }
        
        //Fill ones
        while(one--) {
            temp -> data = 1;
            temp = temp -> next;
        }

        //Fill twos
        while(two--) {
            temp -> data = 2;
            temp = temp -> next;
        }
    }
}

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(2);
    Node* fourth = new Node(0);
    Node* fifth = new Node(0);
    Node* sixth = new Node(0);

    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = sixth;

    cout << "Input LL : ";
    print(head);

    sortZeroOneTwo(head);

    cout << endl;
    cout << "After sorting LL : ";
    print(head);

    return 0;
}