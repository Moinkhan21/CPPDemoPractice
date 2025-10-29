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

Node* sortLL(Node* head) {

    if(head == NULL) {
        cout << "LL is empty" << endl;
        return NULL;
    }
    if(head -> next == NULL) {
        //Single node in LL
        return head;
    }

    //Create dummy nodes
     Node* zeroHead = new Node(-1);
     Node* zeroTail = zeroHead;

     Node* oneHead = new Node(-1);
     Node* oneTail = oneHead;

     Node* twoHead = new Node(-1);
     Node* twoTail = twoHead;

     //Traverse the original LL
     Node* curr = head;
     while(curr != NULL) {
        if(curr -> data == 0) {
            //Take out the zero wali node
            Node* temp = curr;
            curr = curr -> next;
            temp -> next = NULL;

            //Append the zero node in zeroHead LL
            zeroTail -> next = temp;
            zeroTail = temp;

        }
        else if(curr -> data == 1) {
            //Take out the one wali node
            Node* temp = curr;
            curr = curr -> next;
            temp -> next = NULL;

            //Append the one node in zeroHead LL
            oneTail -> next = temp;
            oneTail = temp;

        }else if(curr -> data == 2) {
            //Take out the two wali node
            Node* temp = curr;
            curr = curr -> next;
            temp -> next = NULL;

            //Append the two node in zeroHead LL
            twoTail -> next = temp;
            twoTail = temp;
        }
     }

     //Modify one wali list
     Node* temp = oneHead;
     oneHead = oneHead -> next;
     temp -> next = NULL;
     delete temp;

     //Modify two wali list
     temp = twoHead;
     twoHead = twoHead -> next;
     temp -> next = NULL;
     delete temp;

     //Join list
     if(oneHead != NULL) {
        //One wali list is non-empty
        //Zero wali list ko one wali list se attach krdia
        zeroTail -> next = oneHead;
        
        if(twoHead != NULL) {
            oneTail -> next = twoHead;
        }
     }
     else {
        //One wali list is empty
        if(twoHead != NULL) {
            zeroTail -> next = twoHead;
        }
     }

     //remove zerohead dummy node
     temp = zeroHead;
     zeroHead = zeroHead -> next;
     temp -> next = NULL;
     delete temp;

     //return head of the modified linked list
     return zeroHead;
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

    //Node* temp = NULL; //for passing NULL in LL
    head = sortLL(head);

    cout << endl;
    cout << "After sorting LL : ";
    print(head);

    return 0;
}