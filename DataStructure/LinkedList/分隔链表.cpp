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

以下是自解方法，可能稍显繁琐，逻辑和编程都有一些难度但不大，细节较多考验一些基本功

其中有一个（？ ：） 表达式比较精髓，消除了一些特例，保证统一性

*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> result;
        ListNode* countPiont = root;
        int count = 0;
        while(countPiont){
            count++;
            countPiont = countPiont->next;
        }
        countPiont = root;
        int quotient = count/k;
        int remainder = count%k;

        if(quotient == 0 || (quotient == 1 && remainder == 0)){
            for(int i = 0; i < k; i++){
                if(countPiont != NULL){
                    ListNode* temp = new ListNode(countPiont->val);
                    result.push_back(temp);
                    countPiont = countPiont->next;
                }else{
                    ListNode* temp = NULL;
                    result.push_back(temp);
                }
            }
        }else{
            for(int i = 0; i < k; i++){
                ListNode* temp = new ListNode(-1);
                ListNode* iPoint = temp;
                for(int j = 0; j < quotient + (i < remainder ? 1 : 0); j++){
                    iPoint->next = new ListNode(countPiont->val);
                    iPoint = iPoint->next;
                    countPiont = countPiont->next;
                }
                result.push_back(temp->next);
                delete temp;
            }
        }
        return result;
    }
};