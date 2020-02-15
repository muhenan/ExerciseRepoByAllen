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
自解方法，完美！
每次都寻找局部最优！
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = prices.size();
        if(count == 0 || count == 1) return 0;
        int res = -1;
        int min = prices[0];
        for(int i = 1; i < count; i++){
            if(prices[i] < min){min = prices[i]; continue;}
            else  res = max(res, prices[i] - min);
        }
        return (res > 0 ? res : 0);
    }
};