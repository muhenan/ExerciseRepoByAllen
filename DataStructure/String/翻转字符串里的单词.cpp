#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

// leetcode 151

/*

每一个单词每一个单词的找出来，然后加成一个字符串，其中要注意一些细节吧

细节的编程思想：
    bool inAWord 这个 flag 的使用

*/

class Solution {
public:
    string reverseWords(string s) {
        string res;
        string word;
        int count = s.size();
        bool inAWord = false;
        for(int i = 0; i < count; i++){
            if(s.at(i) == ' '){
                if(!inAWord) continue;
                else{
                    res = word + ' ' + res;
                    word.clear();
                    inAWord = !inAWord;
                }
            }else{
                word += s.at(i);
                if(!inAWord) inAWord = !inAWord;
            }
        }
        if(!word.empty()) res = word + ' ' + res;
        res.pop_back();
        return res;
    }
};

/*

一下是 leetcode 大神的原地做法

其中一些细节非常值得好好体会

思路是先一个整体的翻转，再逐个翻转单词

操作细节：
    整体翻转
    通过左右两个指针除去左右的空格
    单词逐个翻转，两个指针，找到单词，然后 reverse 函数
    一个精髓之处在于处理中间冗余空格：
        完全原地操作，覆盖冗余空格，tail i 两个指针，妙至毫巅
        覆盖的整个过程不会影响后面，但是前面得到了正确结果

字符串还是需要一些操作的


*/

string reverseWords(string s) {
    reverse(s.begin(), s.end());                        //整体反转
    int start = 0, end = s.size() - 1;
    while (start < s.size() && s[start] == ' ') start++;//首空格
    while (end >= 0 && s[end] == ' ') end--;            //尾空格
    if (start > end) return "";                         //特殊情况

    for (int r = start; r <= end;) {                    //逐单词反转
        while (s[r] == ' '&& r <= end) r++;
        int l = r;
        while (s[l] != ' '&&l <= end) l++;
        reverse(s.begin() + r, s.begin() + l);
        r = l;
    }

    int tail = start;                                   //处理中间冗余空格
    for (int i = start; i <= end; i++) {
        if (s[i] == ' '&&s[i - 1] == ' ') continue;
        s[tail++] = s[i];
    }
    return s.substr(start, tail - start);
}