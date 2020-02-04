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

以下是一个自解方法，时间和空间方面都可以说是通过的题解中的最低水平

思路：
    最长路径肯定存在一个中间结点，也就是最上面的结点
    如果认定一个结点为中间结点，那么路径就是左树的最大深度加右数的最大深度
    但这个中间结点不一定是 root
    所以对每一个结点当成中间结点求最大路径然后取最大

总结评价：可以说是树高那道题的延申

*/

//这样相当于递归了两遍，求高度时也在递归，求直径时又递归求高度，白白浪费时间复杂度

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int left = diameterOfBinaryTree(root->left);
        int right = diameterOfBinaryTree(root->right);
        return max(max(left,right),maxDepth(root->left) + maxDepth(root->right));
    }
    int maxDepth(TreeNode* root) {
        return (root==NULL)? 0:max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

// 这种效率提高了很多，但还是处于较低水平

class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        maxDepth(root);
        return ans;
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        ans = max(ans , left + right);
        return max(left,right)+1;
    }
};