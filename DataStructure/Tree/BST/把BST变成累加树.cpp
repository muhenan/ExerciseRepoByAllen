#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>   // 层次遍历  BFS
#include<stack>   // 循环遍历
#include<map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*

反向中序遍历，没有任何问题

非常漂亮，效率很好

*/

class Solution {
public:
    int countNumber = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(!root) return NULL;
        convertBST(root->right);
        root->val += countNumber;
        countNumber = root->val;
        convertBST(root->left);
        return root;
    }
};

