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

题目要求：
1. 一遍遍历
2. 仅占用常数的空间

*/


/*

以下是自己想出的一种巧妙方法，但可惜之处在于这种方法只能解决数值是 0-9 的情况

因为运用了哈希表，所以就有了数值的局限性

但他一遍走完通过 index 存在的某种数学关系完成判断

属于 “ 逻辑复杂，编程简单 ” 的情况

*/


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int arr[10];
        for(int i = 0; i < 10; i++) arr[i] = 0;
        ListNode* iPoint = head;
        int count = 0;
        while(iPoint){
            count++;
            arr[iPoint->val] += count;
            iPoint = iPoint->next;
        }
        if(count % 2 == 1){
            for(int i = 0; i < 10; i++){
                if(arr[i] % (count/2 + 1) != 0) return false;
            }
            return true;
        }else{
            for(int i = 0; i < 10; i++){
                if(arr[i] % (count + 1) != 0) return false;
            }
            return true;
        }
    }
};


/*

不论什么数值都能解决的普适性方法
O(n) 时间复杂度，且完全不占用额外的空间

属于 “ 逻辑简单，编程困难的方法 ”

所以这样就变成了一个对编程基本功基本函数的考验！
（基本功要扎实）
*/


/*

对几个子函数的说明：
    总体思路：切成两半，把后半段反转，然后比较两半是否相等

    1.cut 函数：
        这个函数在 cutNode 处 cut，使 cutNode 前面的执政不再指向他而是指向 NULL 来完成 cut
    2.reverse 函数：
        经典的链表翻转，下面写法不利用任何额外空间，仅仅在原链表上通过指针的变换完成翻转！！（顶！！！！！）
    3.isEqual 函数：
        这个函数的精髓在于，判断一样的返回 true，如果有一个多一个结点，但前面两者都一样，也 true
        （这样就统一解决了奇数偶数的问题！！）

*/

class Solution {
public:
    bool isPalindrome(ListNode* head){
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast != NULL) slow = slow->next;  // 偶数节点，让 slow 指向下一个节点
        cut(head, slow);                     // 切成两个链表
        return isEqual(head, reverse(slow));
    }
    void cut(ListNode* head, ListNode* cutNode){
        while(head->next != cutNode) head = head->next;
        head->next = NULL;
    }
    ListNode* reverse(ListNode* head){
        ListNode* newhead = NULL;
        while(head != NULL){
            ListNode* next = head->next;
            head->next = newhead;
            newhead = head;
            head = next;
        }
        return newhead;
    }
    bool isEqual(ListNode* l1, ListNode* l2){
        while(l1 != NULL && l2 != NULL){
            if(l1->val != l2->val) return false;
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }
};