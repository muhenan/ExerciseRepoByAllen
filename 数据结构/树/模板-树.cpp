#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*

树
树是一种递归结构
很多树的问题都可以用递归来解决

*/


// 两树相等
bool isSame(TreeNode* s, TreeNode* t) {
    if(!s && !t) return true;
    if(s && t && s->val == t->val && isSame(s->left,t->left) && isSame(s->right,t->right)) return true;
    return false;
}

// 最大深度
    int maxDepth(TreeNode* root) {
        return (root==NULL)? 0:max(maxDepth(root->left),maxDepth(root->right))+1;
    }