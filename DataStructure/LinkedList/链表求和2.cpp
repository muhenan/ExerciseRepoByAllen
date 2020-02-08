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

/*

以下是一个比较简单的思路，是堆栈的使用

大体思路：把两个数的东西放入 stack 中，然后再取出，相加，合成新的数

*/

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
        ListNode* result = NULL;
        int carry = 0;
        while(!FirstNumber.empty() && !SecondNumber.empty()){
            int sum = (FirstNumber.top() + SecondNumber.top() + carry) % 10;
            carry = (FirstNumber.top() + SecondNumber.top() + carry) / 10;
            FirstNumber.pop();
            SecondNumber.pop();
            ListNode* LeftNode = new ListNode(sum);
            LeftNode->next = result;
            result = LeftNode;
        }
        while(!FirstNumber.empty()){
            int sum = (FirstNumber.top() + carry) % 10;
            carry = (FirstNumber.top() + carry) / 10;
            FirstNumber.pop();
            ListNode* LeftNode = new ListNode(sum);
            LeftNode->next = result;
            result = LeftNode;
        }
        while(!SecondNumber.empty()){
            int sum = (SecondNumber.top() + carry) % 10;
            carry = (SecondNumber.top() + carry) / 10;
            SecondNumber.pop();
            ListNode* LeftNode = new ListNode(sum);
            LeftNode->next = result;
            result = LeftNode;
        }
        if(carry != 0){
            ListNode* LeftNode = new ListNode(1);
            LeftNode->next = result;
            result = LeftNode;
        }
        return result;
    }
};

//以下是代码优化一些的写法

// 下面这种写法 是一种消除差异性，追求一致性的好的例子 （考虑周全是永恒的问题）

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
        ListNode* result = NULL;
        int carry = 0;
        while(!FirstNumber.empty() || !SecondNumber.empty() || carry){
            int x = 0;
            int y = 0;
            if(!FirstNumber.empty()){
                x = FirstNumber.top();
                FirstNumber.pop();
            }
            if(!SecondNumber.empty()){
                y = SecondNumber.top();
                SecondNumber.pop();
            }
            int sum = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            ListNode* LeftNode = new ListNode(sum);
            LeftNode->next = result;
            result = LeftNode;
        }
        return result;
    }
};