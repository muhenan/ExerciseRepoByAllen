#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<stack>
#include<map>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 题目要求：不允许翻转链表

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        stack<int> FirstNumber;
        stack<int> SecondNumber;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while(temp1){
            FirstNumber.push(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2){
            SecondNumber.push(temp2->val);
            temp2 = temp2->next;
        }
        
    }
};