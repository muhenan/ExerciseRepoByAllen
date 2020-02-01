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

题目要求：不能改变数值，必须交换结点

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

这里用了一个 dummy ，同样，是为了保证每一组交换的时候都有上一个，保持一个统一性，消除特例！
(下面的写法直接复制 leetcode dummy没有注意删除直接内存泄漏了，leetcode一贯的风格... ,自己写的时候要注意)

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