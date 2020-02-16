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


/*
以下为note大神解法：
怎么说，可以说是这道题的种花都有一个统一的标准吧
遇到一个两边都没有的情况就种，种完了赋值为 1，然后再往下
其实是保证了局部最优！！！！！
*/
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int len = flowerbed.size();
        int count = 0;
        for(int i = 0; i < len && count < len; i++){
            if(flowerbed.at(i) == 1) continue;
            int pre = (i == 0 ? 0 : flowerbed.at(i-1));
            int next = (i == len - 1? 0 : flowerbed.at(i+1));
            if(pre == 0 && next == 0){
                count++;
                flowerbed.at(i) = 1;
            }
        }
        return (count >= n);
    }
};