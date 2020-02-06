#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>   // 层次遍历  BFS
#include<map>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 在上一题层次遍历的基础上，改了一下，依旧层次遍历，每次取第一个
// 自解方法

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res = root->val;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int count = que.size();
            for(int i = 0; i < count; i++){
                TreeNode* temp = que.front();
                if(i == 0) res = temp->val;
                if(temp->left) que.push(temp->left);
                if(temp->right) que.push(temp->right);
                que.pop();
            }
        }
        return res;
    }
};


/*

note大神
依旧是层次遍历，从右往左的层次遍历
同样的思想，这样再稍微改下，即可很容易找到右下！！
牛皮！！！！！
队列牛皮！！！！
层次遍历牛皮！！！

*/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> TempQueue;
        TempQueue.push(root);
        while(!TempQueue.empty()){
            root = TempQueue.front();
            TempQueue.pop();
            if(root->right) TempQueue.push(root->right);
            if(root->left) TempQueue.push(root->left);
        }
        return root->val;
    }
};