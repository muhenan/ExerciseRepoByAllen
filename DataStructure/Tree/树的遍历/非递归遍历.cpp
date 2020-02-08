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

关于递归和迭代的问题

但这个函数的参数表，返回值，是复杂的数据结构，不适合迭代时，递归是很好的选择

数据结构是妙用，stack 和 遍历

*/



class Solution {
public:
    // 144 非递归先序遍历
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> tempStack;
        if(!root) return ret;
        tempStack.push(root);
        while(!tempStack.empty()){
            TreeNode* temp = tempStack.top();
            ret.push_back(temp->val);
            tempStack.pop();
            if(temp->right) tempStack.push(temp->right);  // 这里要先右后左，因为是 stack ，因为要保证 左树先遍历
            if(temp->left) tempStack.push(temp->left);
        }
        return ret;
    }
    // 145 非递归后序 
    // 前序遍历为 root -> left -> right，后序遍历为 left -> right -> root
    // 可以修改前序遍历成为 root -> right -> left，那么这个顺序就和后序遍历正好相反
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> ret;
        stack<TreeNode*> tempStack;
        if(!root) return ret;
        tempStack.push(root);
        while(!tempStack.empty()){
            TreeNode* temp = tempStack.top();
            ret.push_back(temp->val);
            tempStack.pop();
            if(temp->left) tempStack.push(temp->left);
            if(temp->right) tempStack.push(temp->right);  // 这里要先左后右，因为是 stack ，因为要保证 右树先遍历
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
    //94 非递归中序   
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> S;
        vector<int> v;
        TreeNode* curr = root;
        while(curr || !S.empty()){
            while(curr){
                S.push(curr);
                curr=curr->left;
            }
            curr=S.top();
            S.pop();
            v.push_back(curr->val);
            curr=curr->right;
        }
        return v;        
    }
};


/*

这里总结以下非递归遍历，leetcode有大神的通用总结非常漂亮可看

关于自己的认识：

先序的话
    root -> left -> right
    用自己的栈的方法，非常的通俗易懂
    即先搞自己，然后出栈，然后右边的入栈，左边的入栈，以此类推
后序的话
    left -> right -> root
    把先序做一个小改动
    得到 root -> right -> left
    然后这个翻转一下，即为结果
中序遍历
    上面也是直接采用了大神的做法
    我看出的思路的话
    因为中序遍历的话，如果是BST应该是有序的
    所以可以说是尽量在找最左的一个，发现一个之后往右走一步再找最左的一个
    整个过程要对应栈的操作
*/