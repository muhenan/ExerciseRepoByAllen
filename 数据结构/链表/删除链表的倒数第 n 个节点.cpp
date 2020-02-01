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

1. 哑结点的巧妙应用
    链表删除添加等问题，在操作第一个或最后一个时
    常出现找不到前一个或者找不到后一个的问题

    这个添加哑结点，就是保证了一定会有前一个
    所以这里就要利用哑结点提供的这个一致条件（都有前一个）
    找要删除的结点的前一个

2. 一遍遍历，通过快慢指针的距离找到要删除的结点的前一个
    然后正常删除
    返回哑结点的next

（这里的两个delete语句是为了保险，防止内存泄漏，如果是做题追求速度和时间，可以暂时不管这些）

*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left = dummy;
        ListNode* right = dummy;
        for(int i = 0; i < n+1; i++) right = right->next;
        while(right){
            left = left->next;
            right = right->next;
        }
        ListNode* to_delete = left->next;
        left->next = left->next->next;
        delete to_delete;
        ListNode* res = dummy->next;
        delete dummy;
        return res;
    }
};