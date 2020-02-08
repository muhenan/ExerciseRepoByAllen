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

果然没有想的简单

先说思路再说细节

思路：
    最简单的思路是 和上题一样，中序遍历得到有序数组，然后遍历这些相邻的（因为BST有序根本不需要绝对值）
    即右边的减去左边的，这样遍历下去，然后找到最小的

细节：
    首先是一个超时的问题，用老的思路超时，所以这让人必须去找新的方法

    在这个中序遍历的过程中，就完成比较，然后在每次的遍历中找最小值

    然后一个细节在于要保存上一个值，绝对值这个词是迷惑人，只要后一个减去前一个就ok，因为BST有序

    第二种leetcode大神的方式是更好，因为他保存的直接是值，第一种是从Java翻译来到所以是保存的指针

    第二种还用多个参数一直传的方式代替了全局变量

    还有一个细节是int最大值用 INT_MAX ，第一次自己的方法错是因为 int 最大值那个提示出来的值并不对

综上，一道有趣的题！！！！！！！！！

*/

class Solution {
public:
    int result = 1000000;
    TreeNode* preNode = NULL;
    int getMinimumDifference(TreeNode* root) {
        if(!root) return result;
        getMinimumDifference(root->left);
        if(preNode){
            int temp = root->val - preNode->val;
            if(temp < result) result = temp;
        }
        preNode = root;
        getMinimumDifference(root->right);
        return result;
    }
};


class Solution {
public:
    void findmin(TreeNode* root, int& prev, int& res) {
        if (root == NULL) return;
        findmin(root->left, prev, res);
        if (prev >= 0) res = min(res, root->val - prev);
        prev = root->val;
        findmin(root->right, prev, res);
    }
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        int res = INT_MAX;
        findmin(root, prev, res);
        return res;
    }
};


