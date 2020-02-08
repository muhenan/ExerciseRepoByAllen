#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>   // 层次遍历  BFS
#include<stack>   // 循环遍历
#include<map>
using namespace std;

/*

非常强势！！！！！！！！！！！

结合上一次的实现 Trie 和 大神的数据存储思想，解决了刁难的前缀置换的情况

number 只在结尾处才赋值，这样可以解决重复前缀置换的问题

然后找到这个之后，就往下找到所有的带这个前缀的字符串求和！！！

精髓在于：
    1.值的存储方式
    2.找其他所有带这个前缀的字符串

*/


class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        this->number = 0;
    }
    ~MapSum(){
        for (int i = 0; i < 26; i++){
            if (next[i] == nullptr) continue;
            delete(next[i]);
            next[i] = nullptr;
        }
    }
    void insert(string key, int val) {
        MapSum *node = this;
        for (auto c : key){
            if (node->next[c - 'a'] == nullptr) node->next[c - 'a'] = new MapSum();
            node = node->next[c - 'a'];
        }
        node->number = val;
    }
    int sum(string prefix) {
        MapSum *node = this;
        int ans = 0;
        for (auto c : prefix){
            if (node->next[c - 'a'] == nullptr) return 0;
            node = node->next[c - 'a'];
        }
        ans = node->number;
        for(int i = 0; i < 26; i++) ans += sum(node->next[i]);
        return ans;
    }
    int sum(MapSum* root){
        if(!root) return 0;
        int ans = root->number;
        for(int i = 0; i < 26; i++) ans += sum(root->next[i]);
        return ans;
    }
private:
    int number = 0;
    bool is_string = false;
    MapSum* next[26] = {nullptr};
};