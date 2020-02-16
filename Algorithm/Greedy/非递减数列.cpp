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
思路至上！！！！！！

贪心，局部最优至上！！！！！！！！！！

对于这道题最局部最优的效果是：让这个子序列是非递减且不影响后续
如果不能保证，则保证，子序列是非递减但影响后续
这才是真正的局部最优！！！！！

出现 nums[i] < nums[i - 1] 时，需要考虑的是应该修改数组的哪个数
使得本次修改能使 i 之前的数组成为非递减数组，并且不影响后续的操作
优先考虑令 nums[i - 1] = nums[i]，因为如果修改 nums[i] = nums[i - 1] 的话
那么 nums[i] 这个数会变大，就有可能比 nums[i + 1] 大，从而影响了后续操作
还有一个比较特别的情况就是 nums[i] < nums[i - 2]，修改 nums[i - 1] = nums[i] 不能使数组成为非递减数组
只能修改 nums[i] = nums[i - 1]

*/

// 思路至上！！！！！！！！！！！！！！！！！！！！！！
// 而不是解决一个又一个的特殊情况！！！！！！！！！！！！！！！！

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        if(len == 0 || len == 1 || len == 2) return true;
        int count = 0;
        for(int i = 1; i < len && count < 2; i++){
            if (nums[i] >= nums[i - 1]) continue;
            count++;
            if (i - 2 >= 0 && nums[i - 2] > nums[i]) nums[i] = nums[i - 1];
            else nums[i - 1] = nums[i];
        }
        return (count <= 1);
    }
};