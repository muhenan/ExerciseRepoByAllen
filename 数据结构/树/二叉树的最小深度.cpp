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

// 自解方法，递归求最小，注意一些小细节

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(left != 0 && right != 0) return (min(left, right)+1) ;
        return (left + right + 1) ;
    }
};