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

自解方法
逻辑简单，编程稍微复杂一点点吧，链表的链接等经典基础问题，基本功吧！

*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* EvenPoint = head->next;
        ListNode* oddi = head;
        ListNode* eveni = head->next;
        while(eveni->next){
            oddi->next = eveni->next;
            oddi = oddi->next;
            if(oddi->next){
                eveni->next = oddi->next;
                eveni = eveni->next;
            }else eveni->next = NULL;
        }
        oddi->next = EvenPoint;
        return head;
    }
};