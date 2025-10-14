// https://www.geeksforgeeks.org/problems/postorder-traversal/1
#include<iostream>
using namespace std;

// Node structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Approach: 1 (recursive way)
// TC: O(n), SC: O(height)
void postOrderHelper(Node *root, vector<int> &res){
    if(root == NULL) return;
    postOrderHelper(root->left, res);
    postOrderHelper(root->right, res);
    res.push_back(root->data);
}
vector<int> postOrder(Node* root) {
    vector<int> res;
    postOrderHelper(root, res);
    return res;
}

// Approach: 2 ()

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> ans = postOrder(root);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}