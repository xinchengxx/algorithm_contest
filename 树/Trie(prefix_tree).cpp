#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

class Trie {
   private:
    vector<Trie*> childs;
    bool isEnd;  // bool变量是否结束
    //输入前缀返回最后一个字符的指针
    Trie* searchPrefix(string prefix) {
        Trie* node = this;  // c++的this指针
        for (int i = 0; i < prefix.size(); i++) {
            char tmp = prefix[i] -= 'a';
            if (node->childs[tmp] == nullptr)
                return nullptr;
            node = node->childs[tmp];
        }
        return node;
    }

   public:
    /** Initialize your data structure here. */

    Trie() : childs(26), isEnd(false) {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i] - 'a';
            if (node->childs[c] == nullptr) {
                node->childs[c] = new Trie();
            }
            node = node->childs[c];
        }
        node->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        if (node != nullptr && node->isEnd == true)
            return true;
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given
     * prefix. */
    bool startsWith(string prefix) {
        return this->searchPrefix(prefix) != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */