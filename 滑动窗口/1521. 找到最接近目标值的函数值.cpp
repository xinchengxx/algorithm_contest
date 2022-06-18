#include <iostream>
#include <vector>
using namespace std;
namespace SegTree {
// 线段树
// 经典的滑动窗口问题
int sum[4 * 100005];
int arr[100005];
void build(int l, int r, int p) {
    if (l == r) {
        sum[p] = arr[r];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, 2 * p);
    build(mid + 1, r, 2 * p + 1);
    sum[p] = sum[2 * p] & sum[2 * p + 1];
}
int query(int ql, int qr, int l, int r, int p) {
    if (ql <= l && qr >= r)
        return sum[p];
    int ans = 0xfffffff;
    int mid = (l + r) >> 1;
    if (ql <= mid)
        ans = ans & query(ql, qr, l, mid, 2 * p);
    if (qr > mid)
        ans = ans & query(ql, qr, mid + 1, r, 2 * p + 1);
    return ans;
}
}  // namespace SegTree

class Solution {
   public:
    //
    int closestToTarget(vector<int>& a, int target) {
        int n = a.size();
        for (int i = 0; i < n; i++)
            SegTree::arr[i + 1] = a[i];
        SegTree::build(1, n, 1);
        int l = 1, r = 1;
        int ans = INT_MAX;

        while (r <= n) {
            int t = SegTree::query(l, r, 1, n, 1);
            if (t < target)
                r = max(++l, r);
            else
                r++;
            ans = min(ans, abs(t - target));
        }
        return ans;
    }
};