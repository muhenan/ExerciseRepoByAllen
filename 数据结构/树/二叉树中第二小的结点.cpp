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

// 递归一下即可 没太多好说

class Solution {
public:
    long int ans[2] = {INTMAX_MAX,INTMAX_MAX};
    int findSecondMinimumValue(TreeNode* root) {
        if(!root) return ans[1];
        if(root->val < ans[0]){
            ans[1] = ans[0];
            ans[0] = root->val;
        }else if(root->val < ans[1] && root->val != ans[0]) ans[1] = root->val;
        findSecondMinimumValue(root->left);
        findSecondMinimumValue(root->right);
        return (ans[1] == INTMAX_MAX ? -1 : ans[1]);
    }
};