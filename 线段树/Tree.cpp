#include <cstdio>
#define M 1000000 + 10
#define ll long long
using namespace std;
int n, m, q;
ll a[M], dp[M * 4], mul[M * 4], add[M * 4];
inline void push_up(int p) {
    dp[p] = (dp[2 * p] + dp[2 * p + 1]) % q;
}
// keep Remember of it
void push_down(int l, int r, int p) {
    //表示push_down
    //保持这个假设
    //好好思考一下
    int m = (l + r) >> 1;
    dp[2 * p + 1] =
        (dp[2 * p + 1] * mul[p] + (r - m) * add[p]) % q;  //先乘后加是人为规定的
    dp[2 * p] = (dp[2 * p] * mul[p] + (m - l + 1) * add[p]) % q;
    mul[2 * p] = (mul[2 * p] * mul[p]) % q;
    add[2 * p] = (add[2 * p] * mul[p] + add[p]) % q;
    mul[2 * p + 1] = (mul[2 * p + 1] * mul[p]) % q;
    add[2 * p + 1] = (add[2 * p + 1] * mul[p] + add[p]) % q;
    mul[p] = 1;
    add[p] = 0;
}
void build(int l, int r, int p) {
    mul[p] = 1;
    if (l == r) {
        dp[p] = a[l];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, 2 * p);
    build(m + 1, r, 2 * p + 1);
    push_up(p);
}

//表示乘法
void update1(int l, int r, int s, int e, int p, int t) {
    if (l <= s && r >= e) {
        dp[p] = (dp[p] * t) % q;
        mul[p] = (mul[p] * t) % q;
        add[p] = (add[p] * t) % q;
        return;
    }
    int m = (s + e) >> 1;
    push_down(s, e, p);
    if (l <= m)
        update1(l, r, s, m, 2 * p, t);
    if (r > m)
        update1(l, r, m + 1, e, 2 * p + 1, t);
    push_up(p);
}

void update2(int l, int r, int s, int e, int p, int t) {
    if (l <= s && r >= e) {
        dp[p] = (dp[p] + (e - s + 1) * t) % q;
        add[p] = (add[p] + t) % q;
        return;
    }
    int m = (s + e) >> 1;
    push_down(s, e, p);
    if (l <= m)
        update2(l, r, s, m, 2 * p, t);
    if (r > m)
        update2(l, r, m + 1, e, 2 * p + 1, t);
    push_up(p);
}

ll query(int l, int r, int s, int e, int p) {
    if (l <= s && r >= e)
        return dp[p];
    ll ans = 0;
    int m = (s + e) >> 1;
    push_down(s, e, p);
    if (l <= m)
        ans = (ans + query(l, r, s, m, 2 * p)) % q;
    if (r > m)
        ans = (ans + query(l, r, m + 1, e, 2 * p + 1)) % q;
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    build(1, n, 1);
    for (int i = 1; i <= m; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            update1(1, n, x, y, 1, k);
        }
        if (op == 2) {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            update2(1, n, x, y, 1, k);
        }
        if (op == 3) {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%lld\n", query(1, n, x, y, 1));
        }
    }
    return 0;
}