#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
struct BIT {
    int n;
    vector<int> tree;
    BIT(int _n) : tree(_n + 1), n(_n){};
    int lowbit(int x) { return x & -x; }
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
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        long long ans = 0;
        int n = nums1.size();
        // 没错这题真是一个好题...
        // 关键在于实现的思想.
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[nums2[i]] = i + 1;
        }
        BIT b(n);
        for (int i = 0; i < n; i++) {
            int pos = m[nums1[i]];
            int left = b.query(1, pos - 1);
            int right =
                n - pos - b.query(pos + 1, n);  // pos + 1.... n  n - pos -
            ans += 1ll * left * right;
            b.update(pos);
        }
        return ans;
    }
};