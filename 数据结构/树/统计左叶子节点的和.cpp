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

// 自解方法，用两个函数在一棵树上进行递归，不同结点用不同函数，还是比较新颖

class Solution {
public:
    int result = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        ItsLeft(root->left);
        sumOfLeftLeaves(root->right);
        return result;
    }
    void ItsLeft(TreeNode* root){
        if(!root) return;
        if(!root->left && !root->right) result += root->val;
        ItsLeft(root->left);
        sumOfLeftLeaves(root->right);
        return;
    }
};


// 简化
// 其实并不是简单的简化代码
// 他利用了一个事实，这个树没有左子树或者左子树的一个叶节点，那么其他的左叶节点一定都在右树上！！！
// 这么看的话，自解方法思路双函数迭代还是挺酷的

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        if(!root->left) return sumOfLeftLeaves(root->right);
        if(!root->left->left && !root->left->right) return (root->left->val + sumOfLeftLeaves(root->right));
        return (sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right));
    }
};
