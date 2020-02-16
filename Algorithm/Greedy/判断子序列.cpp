#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>   // 层次遍历  BFS
#include<stack>   // 循环遍历
#include<map>
using namespace std;
/*

贪心思想：

保证每次操作都是局部最优的，并且最后得到的结果是全局最优的。

*/


// 局部最优一点一点判断

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int lenOfS = s.size();
        int lenOfT = t.size();
        int count = 0;
        int j = 0;
        for(int i = 0; i < lenOfS; i++){
            for(; j < lenOfT; j++){
                if(s.at(i) != t.at(j)) continue;
                else{
                    count++;
                    j++;
                    break;
                }
            }
        }
        return (count == lenOfS);
    }
};



/* 
note大神解法

用了java 的 t.indexOf(c, index + 1) 这个函数

public boolean isSubsequence(String s, String t) {
    int index = -1;
    for (char c : s.toCharArray()) {
        index = t.indexOf(c, index + 1);
        if (index == -1) {
            return false;
        }
    }
    return true;
} */