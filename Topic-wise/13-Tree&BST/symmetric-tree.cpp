// https://leetcode.com/problems/symmetric-tree/description/

#include<iostream>
using namespace std;

// TC: O(n)
// SC: O(n)

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSymmetricHelper(TreeNode* leftSubTree, TreeNode* rightSubTree){
    if(leftSubTree == NULL && rightSubTree == NULL) return true;
    if(leftSubTree == NULL || rightSubTree == NULL) return false;
    if(leftSubTree->val != rightSubTree->val) return false; 
    return isSymmetricHelper(leftSubTree->left,rightSubTree->right) && 
           isSymmetricHelper(leftSubTree->right, rightSubTree->left);
}
bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return isSymmetricHelper(root->left, root->right);
}

int main() {

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool ans = isSymmetric(root);

    if(ans == 1) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}