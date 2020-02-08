#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>   // 层次遍历  BFS
#include<stack>   // 循环遍历
#include<map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 有了上一题的思路，这里完全可以转换成数组然后再做

// 当然，即使不转为数组，思路也是一样的，只是这次的链表操作，要链表找一下中间点

/*

提交之时发现精彩之处

并不是取中间就可以

标答找的是 pre of mid

然后这样才能完成前面那个链表迭代进去时 去掉了最后一个

！！！！！！

至于中间那一个被遗忘了，Java的回收机制！！！！

*/

/*

以下方法还是非常不错的，翻译的大神的Java成cpp

成功找到 pre of mid

中间的一个也完成了很好的删除

这里拓展一下，如果要不改变原来链表的话

可以传两个参数，两个指针 [) 左闭右开的做法，这样也免了删除的操作

反而是更好！！！

（最右边那个对于右边的树，就是NUll；对于左边的树，就是刚刚的 mid！！！）

自己的拓展的方法其实是更好！！！！！

棒！！！！！！

*/

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return new TreeNode(head->val);
        ListNode* PreOfMid = findPreOfMid(head);
        ListNode* mid = PreOfMid->next;
        TreeNode* root = new TreeNode(mid->val);
        ListNode* secondHead = mid->next;
        PreOfMid->next = NULL;
        delete mid;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(secondHead);
        return root;
    }
    ListNode* findPreOfMid(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* pre = head;
        while(right && right->next){
            pre = left;
            left = left->next;
            right = right->next->next;
        }
        return pre;
    }
};