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

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = prices.size();
        if(count == 0 || count == 1) return 0;
        int res = 0;
        int TempMin = prices[0];
        int TempMax = prices[0];
        for(int i = 1; i < count; i++){
            int value = prices[i];
            if(value < TempMax){ 
                res += TempMax - TempMin;
                TempMin = value;
                TempMax = value;
            }
            else if(value > TempMax) TempMax = value;
        }
        res += TempMax - TempMin;
        return res;
    }
};

// 翻译 note 大神的极简解法(不知为何，效率反而低)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int count = prices.size();
        if(count == 0 || count == 1) return 0;
        int res = 0;
        for(int i = 1; i < count; i++){
            if(prices[i] > prices[i - 1]) res += prices[i] - prices[i-1];
        }
        return res;
    }
};