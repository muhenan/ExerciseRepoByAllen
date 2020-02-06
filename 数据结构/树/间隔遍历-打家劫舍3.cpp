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

// 动态规划

/* 
数据结构的妙用 pair 
这道题学到最多的就是，pair 可以解决很多动态规划的重复递归问题！！！！！！！！！！！！！
pair 牛皮！！！！！！！！！
 */

/* 
//自解方法，超时
class Solution {
public:
    int robIt(TreeNode* root, int sum, bool pre){
        if(!root) return sum;
        int No = robIt(root->left, sum, false) + robIt(root->right, 0, false);
        int Yes = robIt(root->left, root->val + sum, true) + robIt(root->right, 0, true);
        if(!pre) return max(No,Yes);
        return No;
    }
    int rob(TreeNode* root) {
        if(!root) return 0;
        int Yes = robIt(root->left, root->val, true) + robIt(root->right, 0, true);
        int No = robIt(root->left, 0, false) + robIt(root->right, 0, false);
        return max(Yes, No);
    }
}; */

/*

一下note给的标答，应该是对的
但同样是超时！！！
interesting！

class Solution{
public:
    int rob(TreeNode* root){
        if(!root) return 0;
        int Yes = root->val;
        if(root->left) Yes += rob(root->left->left) + rob(root->left->right);
        if(root->right) Yes += rob(root->right->left) + rob(root->right->right);
        int No = rob(root->left) + rob(root->right);
        return max(Yes, No);
    }
}; */


/*

一下是 leetcode 大神的题解

思路和我之前的完全不同，之前的动态规划存在各种重复递归

越是到后面，重复递归的越是居多 粗略的算了一下
如果一个结点在第 n 层，那么他将要进入函数 n/2 次
（具体怎么算出，比较简单）

而以下这种方法，每个结点只进入函数一次
因为他可以返回 一个 pair ，这个 pair 代表了这个结点的一切
有了这个就直接搞上面的就可，每个只递归一遍，每个结点得到 pair
牛皮！！！！！！！！！！

*/

class Solution {
public:
    pair<int, int> dfs(TreeNode *root) {
        if (!root) return { 0, 0 };
        auto left_pair = dfs(root->left);
        auto right_pair = dfs(root->right);
        return { root->val + left_pair.second + right_pair.second, 
                max(left_pair.first, left_pair.second) + max(right_pair.first, right_pair.second) };
    }
    int rob(TreeNode* root) {
        auto p = dfs(root);
        return max(p.first, p.second);
    }
};