#include<iostream>
#include<unordered_set>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    
    Node(int x){
        data = x;
        next = nullptr;
    }
};
Node *segregate(Node *head){
    Node* curr = head;
    int cnt0=0, cnt1=0, cnt2=0;
    while(curr != nullptr){
        if(curr->data == 0) cnt0++;
        else if(curr->data == 1) cnt1++;
        else cnt2++;
        curr = curr->next;
    }
    curr = head;
    while(cnt0--){
        curr->data = 0;
        curr = curr->next;
    }
    while(cnt1--){
        curr->data = 1;
        curr = curr->next;
    }
    while(cnt2--){
        curr->data = 2;
        curr = curr->next;
    }
    return head;
}
void printList(Node * node){
    while(node != nullptr){
        cout<<" "<<node->data;
        node = node->next;
    }
    cout<<"\n";
}
/*
//hardcoded input
int main() {
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    cout << "Linked List before Sorting:";
    printList(head);

    segregate(head);

    cout << "Linked List after Sorting:";
    printList(head);

    return 0;
}
*/

int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    if(n <= 0){
        cout << "Invalid size\n";
        return 0;
    }

    cout << "Enter node values (only 0, 1, or 2 allowed):\n";

    int val;
    cin >> val;
    Node* head = new Node(val);
    Node* tail = head;

    for(int i = 1; i < n; i++){
        cin >> val;
        Node* newNode = new Node(val);
        tail->next = newNode;
        tail = newNode;
    }

    cout << "Linked List before Sorting: ";
    printList(head);

    segregate(head);

    cout << "Linked List after Sorting: ";
    printList(head);

    return 0;
}