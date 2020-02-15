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

自解方法，先排序，在分别遍历，找大小关系

放一个 note 大神解法，特别漂亮

public int findContentChildren(int[] grid, int[] size) {
    if (grid == null || size == null) return 0;
    Arrays.sort(grid);
    Arrays.sort(size);
    int gi = 0, si = 0;
    while (gi < grid.length && si < size.length) {
        if (grid[gi] <= size[si]) {
            gi++;
        }
        si++;
    }
    return gi;
}

*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int countG = g.size();
        int countS = s.size();
        int result = 0;
        int j = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        for(int i = 0; i < countG; i++){
            if(j >= countS) break;
            while(j < countS){
                if(s.at(j++) < g.at(i)) continue;
                else {result++; break;}
            }
        }
        return result;
    }
};