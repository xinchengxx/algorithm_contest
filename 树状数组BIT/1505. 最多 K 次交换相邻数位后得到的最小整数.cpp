// BIT别写错了,, 这是个好题, 关键在于BIT需要维护什么东西
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 弄清楚了哈

struct BIT {
    int n;
    vector<int> tree;
    int lowbit(int x) { return x & (-x); }
    BIT(int _n) : tree(_n + 1), n(_n){};
    void update(int x) {
        while (x <= n) {
            tree[x]++;
            x += lowbit(x);
        }
    }
    int get(int x) {
        int ans = 0;
        while (x) {
            ans += tree[x];
            x -= lowbit(x);
        }
        return ans;
    }
    int query(int x, int y) { return get(y) - get(x - 1); }
};

class Solution {
   public:
    string minInteger(string num, int k) {
        // ... 本题是一个树状数组的好题...
        // 关键在于如何实现的........
        // 实际上我们需要搞清楚, 它的偏移量......
        // 然后就
        int n = num.size();
        // 0.......n
        BIT tree(n);
        vector<queue<int>> q(10);
        for (int i = 0; i < num.size(); i++) {
            q[num[i] - '0'].push(i + 1);
        }
        string ans;
        for (int i = 1; i <= num.size(); i++) {
            for (int j = 0; j < 10; j++) {
                if (!q[j].empty()) {
                    int pos = tree.query(q[j].front() + 1, n);
                    int dist =
                        q[j].front() + pos - i;  // i....q[j].front() - 1 + pos
                    if (dist <= k) {
                        k -= dist;
                        ans.push_back(j + '0');
                        tree.update(q[j].front());
                        q[j].pop();
                        break;
                    }
                }
            }
        }
        return ans;
    }
};