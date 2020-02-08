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

// 两数之和，思路和之前有序数组的思路一样
// 搞到有序数组，然后双指针分别从两头开始走

// 还是说一句，这里一个小细节，vector 引用传参

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        inOrder(root,nums);
        int i = 0;
        int j = nums.size() - 1;
        while(i < j){
            int sum = nums.at(i) + nums.at(j);
            if(sum == k) return true;
            if (sum < k) i++;
            else j--;
        }
        return false;
    }
    void inOrder(TreeNode* root,vector<int> & nums){
        if(!root) return;
        inOrder(root->left,nums);
        nums.push_back(root->val);
        inOrder(root->right,nums);
        return;
    }
};

