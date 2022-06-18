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
    sum[p] = sum[2 * p] & sum[2 * p + 1];  //因为或是具有结合律的
}
int query(int ql, int qr, int l, int r, int p) {
    if (ql <= l && qr >= r)
        return sum[p];
    int ans = 0xfffffff;  //注意按位与的ans 初始化问题
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
        // 首先滑动窗口有一个这样的套路
        // 那就是满足窗口移动的单调性
        // 比如说此题需要求的是最靠近的
        // 可以明显通过窗口移动来进行判断
        // 直到窗口移动结束
        // 这个滑动窗口的经典判断条件
        while (r <= n) {
            int t = SegTree::query(l, r, 1, n, 1);
            if (t < target)
                r = max(++l, r);  //左边界右移
            else
                r++;                          //右边界右移
            ans = min(ans, abs(t - target));  //更新结果
        }
        return ans;
    }
};