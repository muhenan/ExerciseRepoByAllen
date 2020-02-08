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

/*

耗费了一些时间

思路：首先自己搞一个函数，这个函数的作用是
    把这个点当成头节点或路径之中的点，然后顺着判断，对的话 result++
    这里注意的是，即使对了，也不要停（不要忙着 return）继续向下可能有 1->(-2) , 1->(-2)->(-1)->1 这种情况

然后就是递归这个函数对每一个结点都使用这个函数，参数都是最初始的 sum

总结：
    看起来是路径不从头开始了，任意开始任意结束
    解决起来还是从头开始，只不过每个都搞一遍
    就这样，不难的
    加油！

*/

class Solution {
public:
    int result = 0;
    void SumThree(TreeNode* root, int sum){
        if(!root) return;
        if(root->val == sum) {result++;}
        SumThree(root->left,sum - root->val);
        SumThree(root->right,sum - root->val);
        return;
    }
    void ForAllSumThree(TreeNode* root, int sum){
        if(!root) return;
        SumThree(root, sum);
        ForAllSumThree(root->left, sum);
        ForAllSumThree(root->right, sum);
    }
    int pathSum(TreeNode* root, int sum) {
        ForAllSumThree(root, sum);
        return result;
    }
};


class Solution {
public:
    int result = 0;
    void SumThree(TreeNode* root, int sum){
        if(!root) return;
        if(root->val == sum) {result++;}
        SumThree(root->left,sum - root->val);
        SumThree(root->right,sum - root->val);
        return;
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root) return result;
        SumThree(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return result;
    }
};