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

// 逻辑最简单的一手递归

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return (root==NULL)? 0:max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};


