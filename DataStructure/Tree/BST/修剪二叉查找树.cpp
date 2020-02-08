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

自解方法，不知道哪里出了问题

我真的自己找不出问题，我准备转 Java 了

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        if(root->val < L || root->val > R){
            if(!root->left && !root->right){
                delete root;
                root = NULL;
            }
            else if(!root->left || !root->right){
                TreeNode* to_delete = root;
                root = (!root->left ? root->right : root->left) ;
                delete to_delete;
            }
            else{
                TreeNode* to_delete = root;
                TreeNode* leftest = root->right;
                if(!leftest->left || !leftest->right){
                    leftest->right = (leftest->left? leftest->left: leftest->right);
                    leftest->left = root->left;
                    root = leftest;
                    delete to_delete;
                }else{
                    while(leftest->left) leftest = leftest->left;
                    root->val = leftest->val;
                    TreeNode* to_delete = leftest;
                    leftest = leftest->right;
                    delete to_delete;
                }
            }
        }
        if(!root) return NULL;
        root->left = trimBST(root->left,L,R);
        root->right = trimBST(root->right,L,R);
        return root;
    }
}; */


// 笔记 大神解法

/* class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        if(root->val > R){
            TreeNode* result = trimBST(root->left,L,R);
            root->left = NULL;
            delete root;
            return result;
        }else if(root->val < L){
            TreeNode* result = trimBST(root->right,L,R);
            root->right = NULL;
            delete root;
            return result;
        }else{
            root->left = trimBST(root->left,L,R);
            root->right = trimBST(root->right,L,R);
            return root;
        }
    }
}; */

// 这种 大神解法实在是不错，但是用C++写造成大片的内存泄露
// 对于做算法题，最稳健的方式就是不管内存泄漏，根本不用 delete 函数，全程在原数据结构上操作

/*

我懂了呀！！！！！！！！！！！！！
大神的解法都是 Java的，Java有垃圾回收机制，所以根本不需要自己删除
这样就省了很多很多的问题啊！！！！！！
我爱了啊！！！！

Java 牛逼！！！！！！！！！！！！！！！

*/


//以下是我用cpp翻译的大神的Java做法，有内存泄漏
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root) return NULL;
        if(root->val > R)   return trimBST(root->left,L,R);
        if(root->val < L)   return trimBST(root->right,L,R);
        root->left = trimBST(root->left,L,R);
        root->right = trimBST(root->right,L,R);
        return root;
    }
};


/*

这里也引出了关于 c++ delete的一些深度的思考
这里发现 c++ delete 存在很多问题，很多时候并不如人们所想

delete之后得到的并不是NULL，而是 一个垃圾值
设为 NULL 也并不会释放内存

*/