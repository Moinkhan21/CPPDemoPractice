#include <iostream>
using namespace std;

void linkdelete(struct Node * head, int M, int N) {
    if(!head) return;
    Node* it = head;
    for(int i = 0; i < M - 1; ++i) {
        //if M nodes are N.A.
        it = it -> next;
    }

    //it -> would be at Mth node;
    if(!it) return;

    Node*MthNode = it;
    it = MthNode -> next;
    for(int i = 0; i < N; ++i) {
        if(!it) break;

        Node* temp = it -> next;
        delete it;
        it = temp;
    }
    MthNode -> next = it;
    linkdelete(it, M, N);
}

int main() {

}