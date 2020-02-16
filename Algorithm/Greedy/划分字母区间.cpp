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
自解方法，每次都追求正确的分组形式，需改变时则进行相应的全盘改变！！！
牛逼！！！！！！！！！！！！！
*/

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        int len = S.size();
        if(len == 0) return res;
        int arr[26];
        for(int i = 0; i < 26; i++) arr[i] = -1;
        res.push_back(1);
        arr[S[0] - 'a'] = 0;
        for(int i = 1; i < len; i++){
            char tempChar = S[i];
            if(arr[tempChar - 'a'] == -1){
                arr[tempChar - 'a'] = res.size();
                res.push_back(1);
            }else{
                int left = res.size() - (arr[tempChar - 'a'] + 1);
                int temp = 1;
                for(int j = left; j > 0; j--){
                    temp += res[arr[tempChar - 'a'] + j];
                    res.pop_back();
                }
                res[arr[tempChar - 'a']] += temp;
                for(int k = 0; k < 26; k++) if(arr[k] > arr[tempChar - 'a']) arr[k] = arr[tempChar - 'a'];
            }
        }
        return res;
    }
};

/* 
leetcode 的一个 cpp 解法，也是非常不错
通过找这个字母最后一次出现的位置来解决
非常不错！！

（比我的效率高很多！！！）

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int N = S.size();
        vector<int> ends(26, -1);
        for (int i = 0; i < N; ++i) {
            ends[S[i] - 'a'] = i;
        }
        vector<int> res;
        int i = 0;
        while (i < N) {
            int r = ends[S[i] - 'a'];
            for (int j = i + 1; j <= r; ++j) {
                r = max(r, ends[S[j] - 'a']);
            }
            res.push_back(r - i + 1);
            i = r + 1;
        }
        return res;
    }
};

作者：da-li-wang
链接：https://leetcode-cn.com/problems/partition-labels/solution/c-jian-dan-ti-jie-by-da-li-wang-12/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */