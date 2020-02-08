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

无奈自己还是菜了些，直接借鉴了note大神的方法

思路的话，递归
因为已经是知道顺序了
所以每次从中间拿一个当根
然后左右都这样递归下去
最后即得到平衡二叉树

这里没有考虑太多 vector 传参的问题
用了 & 引用，应该是和指针一个意思了

这里又体现了大神用Java的一个好处
万物都是指针
不用考虑这个传参太大的问题
！！！
Java牛皮！！！！

（不过我cpp vector & 的传参在这里也还ok）

*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return toBST(nums,0,nums.size() - 1);
    }
    TreeNode* toBST(vector<int>& nums, int leftIndex, int rightIndex){
        if(leftIndex > rightIndex) return NULL;
        int midIndex = leftIndex + (rightIndex - leftIndex)/2 ;
        TreeNode* root = new TreeNode(nums.at(midIndex));
        root->left = toBST(nums, leftIndex, midIndex - 1);
        root->right = toBST(nums, midIndex + 1, rightIndex);
        return root;
    }
};