// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include<iostream>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 /*
//Approach: 1 (Iterative method using stack)
// TC: O(n)
// SC: O(n)
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> st;
    TreeNode *curr = root;
    while(curr != NULL || !st.empty()){
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
    return res;
}
*/

/*
//Approach: 2 (using recursion)
// TC: O(n)
// SC: O(n)

void helper(TreeNode *root, vector<int> &res){
    if(root != NULL){
        helper(root->left, res);
        res.push_back(root->val);
        helper(root->right, res);
    }
}
vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    helper(root, res);
    return res;
}
*/
//Approach: 3 (using morris traversal)
// TC: O(n)
// SC: O(1)

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    TreeNode* curr = root;
    TreeNode* pre;

    while(curr != NULL){
        if(curr->left == NULL){
            res.push_back(curr->val);
            curr = curr->right; //move to next right node
        }else{
            pre = curr->left;
            while(pre->right != NULL && pre->right != curr){
                pre = pre->right;
            }
            if(pre->right == NULL){
                //establish a link back to the current node
                pre->right = curr;
                curr = curr->left;
            }
            else{
                //restore the tree structure
                pre->right = NULL;
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return res;
}
int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    

    vector<int> ans = inorderTraversal(root);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout<<endl;
    return 0;
}
