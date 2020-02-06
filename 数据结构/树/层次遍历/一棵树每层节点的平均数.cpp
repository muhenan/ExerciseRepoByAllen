#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>  
#include<queue>      // 层次遍历  BFS
#include<map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 数据结构的妙用，队列与BFS、层次遍历


/* 
使用 BFS 进行层次遍历。不需要使用两个队列来分别存储当前层的节点和下一层的节点
因为在开始遍历一层的节点时，当前队列中的节点数就是当前层的节点数
只要控制遍历这么多节点数，就能保证这次遍历的都是当前层的节点
 */

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ret;
        if(!root) return ret;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int count = que.size();
            double sum = 0;
            for(int i = 0; i < count; i++){
                TreeNode* temp = que.front();
                que.pop();
                sum += temp->val;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
            }
            ret.push_back(sum/count);
        }
        return ret;
    }
};