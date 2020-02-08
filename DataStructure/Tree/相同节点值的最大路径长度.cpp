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

自解方法

像是之前几种迭代方法的延申

longestUnivaluePath 是把每一个结点当成最上层的一个结点

onPath 是已经有最上面一个了，这条 Path 上最大的路径长

（看了一些题解感觉只有自己的最通俗易懂哈哈哈哈哈哈，虽然耗时也长）

（网友居然说有中等难度哈哈哈哈哈哈哈哈哈哈哈不难的）

*/

class Solution {
public:
    int maxPath = 0;
    int onPath(TreeNode* root, int key, int count){
        if(root && root->val == key) return max(onPath(root->left, root->val, count+1), onPath(root->right, root->val, count+1));
        return count;
    }
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return maxPath;
        int left = onPath(root->left, root->val, 0);
        int right = onPath(root->right, root->val, 0);
        if(left + right > maxPath) maxPath = left + right;
        longestUnivaluePath(root->left);
        longestUnivaluePath(root->right);
        return maxPath;
    }
};