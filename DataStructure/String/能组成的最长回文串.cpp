#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

/*

还是哈希的应用

先遍历一遍搞出计数的哈希表

然后通过奇偶进行操作

偶的直接加，奇的最大的可以加，然后其他的都是减一之后加

这里采取的操作是，都加，然后减去多的奇的

*/

class Solution {
public:
    int longestPalindrome(string s) {
        int arr[128] = {0};
        int count = s.size();
        for(int i = 0; i < count; i++)  arr[s.at(i)]++;
        int res = 0;
        int oddcount = 0;
        for(int i = 0; i < 128; i++){
            res += arr[i];
            if(arr[i] % 2 == 1) oddcount++;
        }
        if(oddcount > 1) res -= (oddcount - 1);
        return res;
    }
};



/* 

note的Java标答，运用了 int 除法的特性

最后再和总体比较，体会一下也是非常精妙

public int longestPalindrome(String s) {
    int[] cnts = new int[256];
    for (char c : s.toCharArray()) {
        cnts[c]++;
    }
    int palindrome = 0;
    for (int cnt : cnts) {
        palindrome += (cnt / 2) * 2;
    }
    if (palindrome < s.length()) {
        palindrome++;   // 这个条件下 s 中一定有单个未使用的字符存在，可以把这个字符放到回文的最中间
    }
    return palindrome;
} */