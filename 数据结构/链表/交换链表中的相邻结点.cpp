#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*

以下两种方法：

时间复杂度为 O(n)

关于空间复杂度：
    1.循环迭代的方法不占用额外内存，O(1)
    2.递归的方法，占用堆栈的空间，O(n)

(本题中并未看出太大区别)

递归和循环两种方法，最大区别在于空间的占用！！！！！！！

编程逻辑方面，递归更易理解

*/

/*

简单的暴力递归

*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* left = head;
        ListNode* right = head->next;
        left->next = right->next;
        right->next = left;
        left->next = swapPairs(left->next);
        return right;
    }
};

/*

循环迭代

*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* node = new ListNode(-1);
        node->next = head;
        ListNode* pre = node;
        while (pre->next != NULL && pre->next->next != NULL) {
            ListNode* l1 = pre->next;
            ListNode* l2 = pre->next->next;
            ListNode* next = l2->next;
            l1->next = next;
            l2->next = l1;
            pre->next = l2;
            pre = l1;
        }
        return node->next;
    }
};