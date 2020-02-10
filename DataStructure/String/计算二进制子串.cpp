#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

// 写在前面：等号是打一个还是两个，永远是最大的马虎，永远这里容易出错

/*

自写代码，细节上不够简洁，思路还是之前回文子串的思想，从中间展开

*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = s.size();
        if(count == 1 || count == 0) return 0;
        int res = 0;
        int start = 0;
        int end = 1;
        while(start >= 0 && end < count){
            char left = s.at(start);
            char right = s.at(end);
            if(left == right){
                start++;
                end++;
                continue;
            }
            int i = start;
            int j = end;
            while(i >= 0 && j < count && s.at(i) == left && s.at(j) == right){
                res++;
                i--;
                j++;
            }
            start++;
            end++;
        }
        return res;
    }
};

/*

以下 note 大神解法，我只能说这还是我不能企及的高度，以下有详细分析

一遍遍历就可以得到结果，因为他有这样一个思想：
    每次都把指着的那个当成最右的，然后判断是不是一个符合要求的子串

prelen是用来记录上一个数字有多少的，curlen是用来循环的
因为当数字改变的时候，prelen 会被赋值为 curlen 来记录上一个数字有多少个
curlen 指回第一个，又开始记录新的这个数字有多少个
如果旧的那个数字的数量大于等于这个新的数字的数量 即 preLen >= curLen
那么就一定有符合标准的子串 count++
再到一个转折的地方，再用 prelen记录下来，curlen再回到最初，curlen表示的又是新的一个了

只能说是妙绝！！！！！！！

总结
    发现规律，可以一遍通过当成最右来判断是否是符合要求
    然后通过指针巧妙的记录前面

！！！！！！！！！！！！
这时突然发现
自己的指针是想多了！！！！！！！！！！

preLen 和 curLen 完全就是两个数

之前大神用的 初始 preLen = 0, curLen = 1完全就是为了计数！！！！！！！！！
curLen = 1 就是记录之前的已经有一个了，就单纯是个数！！！！！
并没有指着什么，是自己想多了！！！！！

综上 
    preLen = 0, curLen = 1 可以用计数来解释
    preLen = -1, curLen = 0 可以用指针来解释

最后发现还是大神的 preLen = 0, curLen = 1 好

！！！！！！！！！！！！！！


*/


class Solution {
public:
    int countBinarySubstrings(string s) {
        int preLen = -1, curLen = 0, count = 0;
        int length = s.size();
        for(int i = 1; i < length; i++){
            if(s.at(i) == s.at(i-1)) curLen++;
            else{
                preLen = curLen;
                curLen = 0;
            }
            if(preLen >= curLen) count++;
        }
        return count;
    }
};

