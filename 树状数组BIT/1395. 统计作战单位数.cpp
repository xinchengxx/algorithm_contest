#include <vector>
using namespace std;

struct BIT {
    int n;
    vector<int> tree;
    BIT(int _n) : tree(n + 1), n(_n){};
    int lowbit(int x) { return x & -x; }
    void update(int x, int val) {
        while (x <= n) {
            tree[x] += val;
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
    const int inf = 1e5;
    int numTeams(vector<int>& rating) {
        // 这个枚举三元组
        int n = rating.size();
        // fenwick tree难的地方是构造出什么需要fenwick tree 维护
        // 这题动态规划肯定可以做n^2
        // 但是fenwick tree该如何做
        // 注意看.......
        // tree[rating].update()

        // 关键在于维护区间和, 我每次的操作都只需要了解部分的区间和,
        // 并且要找到合适的东西来维护, 比如类似于prefix sum一类的性质
        BIT t1(100000), t2(100000);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            t2.update(rating[i], 1);
        }
        for (int i = 0; i < n; i++) {
            int curj = rating[i];

            ans += t1.query(1, curj - 1) * t2.query(curj + 1, inf);
            ans += t1.query(curj + 1, inf) * t2.query(1, curj - 1);
            // cout << curj << " " << t1.query(1, curj - 1) << " " <<
            // t1.query(curj + 1, inf) << " " << t2.query(1, cuj)
            t1.update(rating[i], 1);
            t2.update(rating[i], -1);
        }
        return ans;
    }
};