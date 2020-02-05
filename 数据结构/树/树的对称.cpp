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

// 自解方法，易，思路简单,迭代判断是否对称

// 代码细节就不纠结了，基本都是这个思路

class Solution {
public:
    bool isSym(TreeNode* l, TreeNode* r){
        if(!l && !r) return true;
        if(!l || !r) return false;
        if(l->val !=  r->val) return false;
        else return (isSym(l->right,r->left) && isSym(l->left,r->right));
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSym(root->left, root->right);
    }
};