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

超棒！！！！！！！！！！！
最后一题，自解方法，成功解决

思路：
    中序遍历，分别找出现次数最大的，然后管理结果vector
    其中一些细节，还有处理最后一个这个细节，处理细节最为重要

*/


class Solution {
public:
    int max = 0;
    int count = 0;
    TreeNode* preNode = NULL;
    vector<int> res;
    vector<int> findMode(TreeNode* root) {
        if(!root) return res;
        inorder(root);
        if(count > max){
            res.clear();
            max = count;
            res.push_back(preNode->val);
        }else if(count == max) res.push_back(preNode->val);
        return res;
    }
    void inorder(TreeNode* root){
        if(!root) return;
        inorder(root->left);
        if(preNode){
            if(root->val == preNode->val)   count++;
            else{
                if(count > max){
                    res.clear();
                    max = count;
                    res.push_back(preNode->val);
                }else if(count == max){
                    res.push_back(preNode->val);
                }
                count = 1;
            }
        }else  count = 1;
        preNode = root;
        inorder(root->right);
        return;
    }
};

/*

note中的Java标答和自解方法思路几乎完全一致

但个人感觉自己的方法更好，没有反复的 clear，add，而是只在最后转折的点操作

而且标答的效率不是太高，但是保持了一定的一致性，编程思路更简单一些

没有太多的细节处理，可以说是编程效率更高吧

ok，解决树的最后一道

Goodnight！！！！！！

*/

