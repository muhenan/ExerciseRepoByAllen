#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>   // 层次遍历  BFS
#include<map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 以下是递归实现三种遍历

void preorderTraversal(TreeNode* root){
    if(!root) return;
    cout << root->val << endl;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(TreeNode* root){
    if(!root) return;
    inorderTraversal(root->left);
    cout << root->val << endl;
    inorderTraversal(root->right);
}

void postorderTraversal(TreeNode* root){
    if(!root) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val << endl;
}


