#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

/*

自己思考许久不得其解

一下note大神做法，只能说是太强

想到了是一个个的遍历，然后把它当成回文字符串里特殊的一个去找

当之前一直是想把它当成左起始点，这样导致一直不知道怎么找

大神的做法是把它当成中间点（分奇偶做法），然后两个指针往两边走
如果是相等就 找到一个，一直到最大

！！！！从中间开始找回文字符串
只能说是太强！！！！！！！！！！！！！！！！！！

自己的想法可能总是受到回文链表那道题的影响吧
那道题的标答是 cut 然后 reverse，然后再 isequal 没有什么思维量，考察编程基本功
自解方法计算下表和，也是巧妙的方法，用于计算一个字符串是否是回文比较好，这道题不适合
因为这道题是找有多少个，而不是判断一个确定的字符串是不是回文

extendFromCenter 中的 while 有一个细节，就是东西都放在了 while 的 condition里
这样可以保证该结束的时候早早结束，不会有无用的循环

只能说是太强！！！！！！！！！！！！！！！！！！！！！！！！！！！！！


*/

class Solution {
public:
    int count = 0;
    int countSubstrings(string s) {
        int length = s.size();
        for(int i = 0; i < length; i++){
            extendFromCenter(s,i,i); // 奇数个型
            extendFromCenter(s,i,i+1); //偶
        }
        return count;
    }
    void extendFromCenter(string s, int start, int end){
        int length = s.size();
        while(start >= 0 && end < length && s.at(start) == s.at(end)){
            start--;
            end++;
            count++;
        }
    }
};