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

就这种方法吧，没太多话说

递归思想

翻转左树，翻转右树

左右交换

速度极快，就酱

*/

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode* pre_left = invertTree(root->left);
        TreeNode* pre_right = invertTree(root->right);
        root->left = pre_right;
        root->right = pre_left;
        return root;
    }
};