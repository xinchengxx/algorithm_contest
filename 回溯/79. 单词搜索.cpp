
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {}
    bool dfs(const vector<vector<char>>& bod,
             string word,
             int p,
             int x,
             int y) {
        if (p == word.size() - 1 && word[p] == bod[x][y]) {
            return true;
        }
        if (bod[x][y] != word[p]) {
            return false;
        }
        bool ret = false;
        visit[x][y] = true;
        if ((x + 1) < m && !visit[x + 1][y]) {
            ret |= dfs(bod, word, p + 1, x + 1, y);
        }
        if ((x - 1) >= 0 && !visit[x - 1][y]) {
            ret |= dfs(bod, word, p + 1, x - 1, y);
        }
        if ((y + 1) < n && !visit[x][y + 1]) {
            ret |= dfs(bod, word, p + 1, x, y + 1);
        }
        if ((y - 1) >= 0 && !visit[x][y - 1]) {
            ret |= dfs(bod, word, p + 1, x, y - 1);
        }
        visit[x][y] = false;
        return ret;
    }

   private:
    int m, n;
    bool visit[10][10];
};