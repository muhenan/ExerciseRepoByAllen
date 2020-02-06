#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>   // 层次遍历  BFS
#include<stack>   // 循环遍历
#include<map>
using namespace std;

// c++ 11
class Trie 
{
public:
    /** Initialize your data structure here. */
    Trie() {}
    //对于这个析构函数，我保持质疑
    ~Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            if (next[i] == nullptr) continue;
            delete(next[i]);
            next[i] = nullptr;
        }
    }
    /** Inserts a word into the trie. */
    void insert(string word) 
    {
        Trie *node = this;
        for (auto c : word)
        {
            if (node->next[c - 'a'] == nullptr)
            {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->is_string = true;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) 
    {
        Trie *node = this;
        for (auto c : word)
        {
            if (node->next[c - 'a'] == nullptr) return false;
            node = node->next[c - 'a'];
        }
        return node->is_string;
    }
    // search 和 startsWith 只有一个极小的区别，就是search返回 node->is_string 看是不是结尾
    // 而 startsWith 循环完以后是直接返回 true
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) 
    {
        Trie *node = this;
        for (auto c : prefix)
        {
            if (node->next[c - 'a'] == nullptr) return false;
            node = node->next[c - 'a'];
        }
        return true;        
    }
private:
    bool is_string = false;
    Trie* next[26] = {nullptr};
};

