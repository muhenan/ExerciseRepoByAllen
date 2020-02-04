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

其实可以看作是两树相等的延续

只是说左树中每个结点挑一遍看这个子树是否和右树相等
（这里遍历每一个结点肯定是递归思想）

然后

我喜欢我的 isSame

*/

class Solution {
public:
    bool isSame(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(s && t && s->val == t->val && isSame(s->left,t->left) && isSame(s->right,t->right)) return true;
        return false;
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s) return false;
        if(!t) return true;
        if(isSame(s,t)) return true;
        return (isSubtree(s->left,t) || isSubtree(s->right,t));
    }
};