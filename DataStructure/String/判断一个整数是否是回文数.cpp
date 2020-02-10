#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

/*

要求不能使用额外空间，也就不能将整数转换为字符串进行判断

将整数分成左右两部分，右边那部分需要转置，然后判断这两部分是否相等

思路和自己想的一样，cut reverse isequal

*/


class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0 || x % 10 == 0) return false;
        int right = 0;
        while (x > right) {
            right = right * 10 + x % 10;
            x /= 10;
        }
        return ((x == right) || (x == right / 10));
        }
};

