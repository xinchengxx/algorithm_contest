
#include <cstdio>
int tree[100000 + 10], n, m;
inline int lowbit(int x) {
    return x & -x;
}
void add(int x, int p) {
    while (x <= n) {
        tree[x] += p;
        x += lowbit(x);  //相当于二进制的进位
    }
}

int query(int x) {
    //最后会减成0
    int ans = 0;
    while (x != 0) {
        ans += tree[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        add(i, a);
    }
    for (int i = 1; i < m; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x, k;
            scanf("%d%d", &x, &k);
            add(x, k);
        }
        if (op == 2) {
            int x, y;
            scanf("%d%d", &x, &y);
            printf("%d", query(y) - query(x - 1));
        }
    }
    return 0;
}