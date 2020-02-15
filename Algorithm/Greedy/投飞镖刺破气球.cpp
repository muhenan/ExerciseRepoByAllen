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
// 452 同重复区间

// 以下leetcode标答，注意排序的函数的输入，和他的循环

class Solution {
  public:
  int findMinArrowShots(vector<vector<int>>& points) {
    if (points.size() == 0) return 0;

    // sort by x_end
    sort(begin(points), end(points),
         [](const vector<int> &o1, const vector<int> &o2) {
      return (o1[1] < o2[1]);
    });

    int arrows = 1;
    int xStart, xEnd, firstEnd = points[0][1];
    for (auto p : points) {
      xStart = p[0];
      xEnd = p[1];
      // if the current balloon starts after the end of another one,
      // one needs one more arrow
      if (firstEnd < xStart) {
        arrows++;
        firstEnd = xEnd;
      }
    }
    return arrows;
  }
};