#include <cstdio>
//洛谷的线段树模板2
using namespace std;
#define N 100000 + 10
#define ll long long
int m, n, pn;
ll a[N], dp[4 * N], mul[4 * N], add[4 * N];
inline void push_up(int p) {
    dp[p] = (dp[2 * p] + dp[2 * p + 1]) % pn;
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

void push_down(int l, int r, int p) {
    //考虑一下
    int m = (l + r) >> 1;

    dp[2 * p] = (dp[2 * p] * mul[p] + (m - l + 1) * (add[p])) % pn;
    dp[2 * p + 1] = (dp[2 * p + 1] * mul[p] + (r - m) * add[p]) % pn;
    // update the mul tag
    mul[2 * p] = (mul[2 * p] * mul[p]) % pn;
    mul[2 * p + 1] = (mul[2 * p + 1] * mul[p]) % pn;
    // update the add tag
    add[2 * p] = (add[2 * p] * mul[p] + add[p]) % pn;
    add[2 * p + 1] = (add[2 * p + 1] * mul[p] + add[p]) % pn;
    // recover the father tag
    mul[p] = 1;
    add[p] = 0;
}

// dl dr is the search area
void update1(int l, int r, int dl, int dr, int p, int t) {
    if (dl <= l && dr >= r) {
        // update
        dp[p] = (dp[p] * t) % pn;
        add[p] = (add[p] * t) % pn;
        mul[p] = (mul[p] * t) % pn;
        // do not forget to return
        return;
    }
    int m = (l + r) >> 1;
    push_down(l, r, p);
    if (dl <= m)
        update1(l, m, dl, dr, 2 * p, t);
    if (dr > m)
        update1(m + 1, r, dl, dr, 2 * p + 1, t);
    push_up(p);
    // remember to push_up
}

void update2(int l, int r, int dl, int dr, int p, int t) {
    if (dl <= l && dr >= r) {
        // add
        dp[p] = (dp[p] + (r - l + 1) * t) % pn;
        add[p] = (add[p] + t) % pn;
        return;
    }
    int m = (l + r) >> 1;
    push_down(l, r, p);
    if (dl <= m)
        update2(l, m, dl, dr, 2 * p, t);
    if (dr > m)
        update2(m + 1, r, dl, dr, 2 * p + 1, t);
    push_up(p);
}

ll query(int l, int r, int dl, int dr, int p) {
    if (dl <= l && dr >= r) {
        return dp[p];
    }
    ll ans = 0;
    int m = (l + r) >> 1;
    push_down(l, r, p);
    if (dl <= m)
        ans += query(l, m, dl, dr, 2 * p);
    ans %= pn;
    if (dr > m)
        ans += query(m + 1, r, dl, dr, 2 * p + 1);
    ans %= pn;
    return ans;
}

int main() {
    scanf("%d%d%d", &n, &m, &pn);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
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