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
/*
//Approach: 1 (using unordered_set)
//TC:O(N), SC:O(N)
int lengthOfLoop(Node *head){
    unordered_set<Node*> visited;
    Node* current = head;;
    int count = 0;

    while(current != nullptr){
        if(visited.find(current) != visited.end()){
            Node* startOfLoop = current;
            do{
                count++;
                current = current->next;
            }
            while(current != startOfLoop);
            return count;
        }
        visited.insert(current);
        current = current->next;
    }
    return 0;
}
*/

//Approach: 1 (using Floyd's cycle Detection algorithm(fast, slow))
//TC:O(N), SC:O(1)
int countNodes(Node *node){
    Node *curr = node;
    int cnt = 1;
    while(curr->next != node){
        cnt++;
        curr = curr->next;
    }
    return cnt;
}
int lengthOfLoop(Node *head){
    Node *slow = head, *fast = head;
    int count = 0;

    while(slow != nullptr && fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return countNodes(slow);
    }
    return 0;
}
int main(){
    Node *head = new Node(25);
    head->next = new Node(14);
    head->next->next = new Node(19);
    head->next->next->next = new Node(33);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = head->next;
    cout<<lengthOfLoop(head)<<endl;
    return 0;
}