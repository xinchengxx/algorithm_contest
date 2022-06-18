#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
   public:
    int countHighestScoreNodes(vector<int>& parents) {
        //首先建立一个map
        unordered_map<int, vector<int>> mmap;
        //如何存进map中呢
        int n = parents.size();
        for (int i = 0; i < n; i++) {
            if (parents[i] != -1) {
                if (!mmap.count(parents[i])) {
                    //没有插入父节点的话
                    mmap.emplace(parents[i], vector<int>({i}));
                } else {
                    mmap[parents[i]].push_back(i);  //插入
                }
            }
        }
        //这个表示的是节点数目
        dfs(mmap, 0);
        //计算
        int cnt = 0;
        long long max = 0;
        for (int i = 0; i < n; i++) {
            vector<int> s = mmap[i];
            long long cur = 1;
            for (int i = 0; i < s.size(); i++)
                cur *= score[s[i]];
            int res = score[0] - score[i];
            if (res != 0) {
                cur *= res;
            }
            if (cur == max) {
                cnt++;
            } else if (cur > max) {
                cnt = 1;
                max = cur;
            }
        }
        return cnt;
    }

   private:
    void dfs(unordered_map<int, vector<int>>& mmap, int father) {
        if (!mmap.count(father)) {
            //表示是叶子节点;
            score[father] = 1;
            return;
        } else {
            //否则不是右边的话
            vector<int> temp = mmap[father];
            for (int i = 0; i < temp.size(); i++) {
                dfs(mmap, temp[i]);
                score[father] += score[temp[i]];
            }
            score[father] += 1;
        }
    }
    int score[100000 + 10] = {0};
};