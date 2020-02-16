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
没话说，note大神实在太精妙！！！！！！！！！！！
实在是厉害！！！！！
preSum是负的就肯定不要了，前面不能是有负的，前面有一段负的就意味着一定有更优的结果
正的就加上下一个，每次得到一个新的正的就 max 一下，记录下来
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return 0;
        int preSum = nums[0];
        int maxSum = preSum;
        for (int i = 1; i < len; i++) {
            preSum = (preSum > 0 ? preSum + nums[i] : nums[i]);
            maxSum = max(maxSum, preSum);
        }
        return maxSum;
    }
};