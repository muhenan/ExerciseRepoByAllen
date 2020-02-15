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
leetcode 官方解法已写的非常清楚
首先按身高排由高到低，高度一致的，数量由低到高

然后 insert ，就按照 数量作为 index insert，因为矮的相对于高的是看不见的

所以 insert 矮的的时候，不必管已经 insert的高的
而且已经 insert的肯定不矮于这个将要insert的

这样就保证了每一步都是最优

编程细节：
    排序函数
    insert 时 左边是 iterator 右边是 东西
*/

class Solution 
{
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        //身高降序排列，人数升序排列
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0] > b[0]) 
                return true;
            if(a[0] == b[0] && a[1] <b[1])
                return true;
            return false;
        });
        vector<vector<int>> res;
        for(int i = 0; i < people.size(); i++)  res.insert(res.begin() + people[i][1], people[i]);
        return res;
    }
};