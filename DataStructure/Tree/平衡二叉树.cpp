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

// 平衡二叉树的定义： 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。

/*

思路：
    还是递归的思路
    做题用到了反向的思维，即找反例
    找是平衡二叉树不好找，那就找不是平衡二叉树，发现不是就返回

    所以说这个题的核心就在于找不是平衡二叉树！

*/
class Solution {
public:
    bool result = true;
    bool isBalanced(TreeNode* root) {
        maxDepth(root);
        return result;
    }
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if(abs(l-r) > 1) result = false;
        return max(l,r) + 1;
    }
};

// 这种写法用了一个 -1 的巧妙方式来避免了全局变量，相当于发现 -1 之后就层层向上返回

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root) != -1;
    }
    int depth(TreeNode* root) {
        if (root == NULL) return 0;
        int left = depth(root->left);
        if(left == -1) return -1;
        int right = depth(root->right);
        if(right == -1) return -1;
        return abs(left - right) < 2 ? max(left, right) + 1 : -1;
    }
};
