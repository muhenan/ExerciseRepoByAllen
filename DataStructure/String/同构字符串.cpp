#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

/*

自解方法其实也比较有思维量，只是始终没有成功，算是一个错误的答案

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int Scount = s.size();
        int Tcount = t.size();
        if(Scount != Tcount) return false;
        int count = Scount;
        if(count == 0) return true;
        int hashOfS[128] = {0};
        int hashOfT[128] = {0};
        int S_sum_arr[count] = {0};
        int T_sum_arr[count] = {0};
        int S_increase_arr[count] = {0};
        int T_increase_arr[count] = {0};
        for(int i = 0; i < count; i++){
            char tempS = s.at(i);
            char tempT = t.at(i);
            hashOfS[tempS]++;
            hashOfT[tempT]++;
            S_increase_arr[i] = hashOfS[tempS];
            T_increase_arr[i] = hashOfT[tempT];
        }
        for(int i = 0; i < count; i++)  S_sum_arr[i] = hashOfS[s.at(i)];
        for(int i = 0; i < count; i++)  T_sum_arr[i] = hashOfT[t.at(i)];
        for(int i = 0; i < count; i++){
            if(S_sum_arr[i] != T_sum_arr[i]) return false;
            if(S_increase_arr[i] != T_increase_arr[i]) return false;
        }
        return true;
    }
}; */

/*
note 大神的思路：
    “记录一个字符上次出现的位置，如果两个字符串中的字符上次出现的位置一样，那么就属于同构。”

可以说是一针见血吧

一些细节：
    用到了哈希表
    把数组初始化成 -1 好像并不是一件容易的事
    所以这里用了比较简单的初始化为0
    0 作为一个初始状态，作为一个字符未出现过时的状态
    每次记录的这个index，并不是这个真实的index，而是从1开始的计数，这样来避开0
    对于每个字符比较上次出现的位置

*/


class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int Scount = s.size();
        int Tcount = t.size();
        if(Scount != Tcount) return false;
        int count = Scount;
        if(count == 0 || count == 1) return true;
        int preIndexOfS[128] = {0};
        int preIndexOfT[128] = {0};
        for(int i = 0; i < count; i++){
            char tempS = s.at(i);
            char tempT = t.at(i);
            if(preIndexOfS[tempS] != preIndexOfT[tempT]) return false;
            preIndexOfS[tempS] = i+1;
            preIndexOfT[tempT] = i+1;
        }
        return true;
    }
};