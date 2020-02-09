#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>
#include<string>
using namespace std;

//哈希表的一些应用吧！
//易！

class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[26] = {0};
        int counts = s.size();
        for(int i = 0; i < counts; i++) arr[s.at(i) - 'a']++;
        int countt = t.size();
        if(counts != countt) return false;
        for(int i = 0; i < countt; i++) arr[t.at(i) - 'a']--;
        for(int i = 0; i < 26; i++){
            if(arr[i] != 0) return false;
        }
        return true;
    }
};