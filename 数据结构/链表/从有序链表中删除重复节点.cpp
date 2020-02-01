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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode* left = head;
        ListNode* right = head->next;
        while (right)
        {
            if(left->val == right->val){
                ListNode* to_delete = right;
                right = right->next;
                left->next = right;
                delete to_delete;
            }else{
                right = right->next;
                left = left->next;
            }
        }
        return head;
    }
};

/*

暴力递归！

时间和空间的效果反而要更好

*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};