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

自解方法，最简单的中序遍历的方法
中序遍历一遍，第 k 个记录下来，最后返回这个
思路非常简单，一看即会
但小缺点在于，把全部都遍历了一遍

*/

class Solution {
public:
    int count = 0;
    int result = 0;
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return result;
        if(root->left) kthSmallest(root->left,k);
        count++;
        if(count == k) result = root->val;
        if(root->right) kthSmallest(root->right,k);
        return result;
    }
};

//计算结点数目的方法
// note大神的方法，这个方法也很好，通过计算结点数来找第k个最小的
/*

果然，这种方法的效率反而更低
因为存在重复的计算
例如需要计算左树的总节点数，然后到左子树又要再计算总节点数
这样存在重复的递归和计算
很多结点都被 count 这个函数搞过多遍
所以这种函数的效率也是低的

最后看来竟然是中序遍历最好

*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int leftCount = count(root->left);
        if(leftCount == k - 1) return root->val;
        if(leftCount > k - 1) return kthSmallest(root->left,k);
        return kthSmallest(root->right,k - leftCount - 1);
    }
    int count(TreeNode* root){
        if(!root) return 0;
        else return (1 + count(root->left) + count(root->right));
    }
};