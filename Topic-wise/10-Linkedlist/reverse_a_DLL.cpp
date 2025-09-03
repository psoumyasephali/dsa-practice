#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

//using stack
Node *reverse(Node *head) {
    if(!head) return NULL;
    Node * temp = head;
    stack<int> st;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp=head;
    while(temp != NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}
void printList(Node *node) {
    while (node != nullptr) {
        cout << node->data;
        if(node->next != nullptr){
            cout << " <-> ";
        }
        node = node->next;
    }
}
int main() {
  
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head = reverse(head);
    printList(head);

    return 0;
}