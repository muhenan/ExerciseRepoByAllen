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
头插法
Time complexity : O(n)
Space complexity : O(n) 另外占用了一个这么长的链表的空间，使用了外部空间

*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* res;
        if(!head) return NULL;
        else{
            ListNode* to_delete = head;
            res = new ListNode(head->val);
            head = head->next;
            delete to_delete;
        }
        while(head)
        {
            ListNode* temp = new ListNode(head->val);
            temp->next = res;
            res = temp;
            ListNode* to_delete = head;
            head = head->next;
            delete to_delete;
        }
        return res;
    }
};

/*
原地翻转
Time complexity : O(n)
Space complexity : O(1) 不使用外部空间

*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode* NextOfCurr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = NextOfCurr;
        }
        return prev;
    }
};