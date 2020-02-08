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
nb
若相交，链表A： a+c, 链表B : b+c. a+c+b = b+c+a 。则会在公共处c起点相遇。
若不相交，a+b = b+a 。因此相遇处是NULL 
*/


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        ListNode * pA = headA;
        ListNode * pB = headB;
        while (pA != pB) {
            pA = pA == NULL ? headB : pA->next;
            pB = pB == NULL ? headA : pB->next;
        }
        return pA;
    }
};