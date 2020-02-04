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

自解方法：

（递归思想）

在 t1 的基础上进行 merge ，让 t1 变成最后的结果

*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 || !t2) return (t1 ? t1 : t2);
        t1->val = t1->val + t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};


/* 

以下是GitHub笔记中的标答 Java写到

我个人认为不是太好，这种做法的确没有改变 t1 t2
这相比于我的 t1 变结果是一个改进
但是这种写法并没有完成 弄出一个新的 answer 空间
最大的问题就在于
他在后期一个树有而另一个树是 NULL的时候会至今返回 那个不是NULL的树
也就是说最后指着的是 t1 或者 t2 的最后
（可以想象一下最后那个答案的结构是比较乱的，最后的指针都指着原来 t1 或 t2）

总而言之感觉一般吧，想搞出新的答案空间，但最后四不像，一半一半了

    public TreeNode mergeTrees(TreeNode t1, TreeNode t2) {
    if (t1 == null && t2 == null) return null;
    if (t1 == null) return t2;
    if (t2 == null) return t1;
    TreeNode root = new TreeNode(t1.val + t2.val);
    root.left = mergeTrees(t1.left, t2.left);
    root.right = mergeTrees(t1.right, t2.right);
    return root;
} */