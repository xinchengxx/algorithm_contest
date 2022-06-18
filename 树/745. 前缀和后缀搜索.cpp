// 字典树的应用
#include <bits/stdc++.h>
using namespace std;

class Trie {
public:
    struct TrieNode {
        vector<int> weight;
        TrieNode *next[26] = {nullptr};
    };
    Trie() : root(new TrieNode) {}
    
    void insert(string &word, int weight) {
        TrieNode *p = root;
        for (int i = 0; i < word.size(); ++i) {
            int index = word[i] - 'a';
            if (p->next[index] == nullptr) {
                p->next[index] = new TrieNode;
            }
            p = p->next[index];
            p->weight.push_back(weight);
        }
    }
    vector<int>* startsWith(string &prefix) {
        TrieNode *p = root;
        for (int i = 0; i < prefix.size(); ++i) {
            int index = prefix[i] - 'a';
            if (p->next[index] == nullptr) return nullptr;
            p = p->next[index];
        }
        return &(p->weight);
    }
private:
    TrieNode *root;
};

class WordFilter {
public:
    WordFilter(vector<string>& words) : pre(new Trie), suf(new Trie), count(words.size()){
        for(int i = 0; i < words.size(); ++i){
            pre->insert(words[i], i);
            reverse(words[i].begin(), words[i].end());
            suf->insert(words[i], i);
        }
    }
    
    int f(string prefix, string suffix) {
        if(prefix.empty() && suffix.empty())  return count-1;
        auto pre_v = pre->startsWith(prefix);
        reverse(suffix.begin(), suffix.end());
        auto suf_v = suf->startsWith(suffix);
        
        if(!pre_v || !suf_v)  return -1; 
        if(prefix.empty()) return *(suf_v->end()-1);
        if(suffix.empty())  return *(pre_v->end()-1);
        vector<int>::iterator it1 = pre_v->end()-1, it2 = suf_v->end()-1;      
        while(it1 >= pre_v->begin() && it2 >= suf_v->begin()){
            if(*it1 == *it2)    return *it1;
            *it1 < *it2 ? --it2 : --it1;
        }
        return -1;
    }
private:
    Trie *pre;
    Trie *suf;
    int count;
};
