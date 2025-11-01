// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2025-11-01

// TC: O(m+n)
// SC: O(m)

#include<iostream>
#include<unordered_set>
using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> st(nums.begin(), nums.end());
    // Handle head
    while(head != NULL && st.find(head->val) != st.end()){
        ListNode *temp = head;
        head = head->next;
        // delete(temp);
    }
    ListNode *curr = head;
    while(curr != NULL && curr->next != NULL){
        if(st.find(curr->next->val) != st.end()){
            ListNode *temp = curr->next;
            curr->next = curr->next->next;
            // delete(temp);
        }
        else{
            curr = curr->next;
        }
    }
    return head;
}

// int main(){
//     vector<int> nums = {1, 2, 3};
//     // Linked list: 1 -> 2 -> 3 -> 4 -> 5
//     ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
//     head = modifiedList(nums, head);

//     while(head){
//         cout<<head->val<<" ";
//         head = head->next;
//     }
//     return 0;
// }


int main(){
    int n;
    cout<< "Enter number of elements in nums: ";
    cin>>n;
    vector<int> nums(n);
    cout<< "Enter elements in nums: ";
    for(int i=0; i<n; i++){
        cin>>nums[i];
    }
    int m;
    cout<< "Enter number of nodes in linked list: ";
    cin >>m;
    cout<< "Enter linked list elements: ";
    ListNode *head = NULL;
    ListNode *tail = NULL;
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        ListNode *newNode = new ListNode(x);
        if(!head){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    head = modifiedList(nums, head);
    cout<< "Modified linked list: ";
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}