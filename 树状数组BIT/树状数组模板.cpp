//核心思想在于树状数组每个数管辖的元素
//例如c[6]=c[110]管辖的是c[110]开始往后的10(2)个元素
//所以进位的元素全都需要被管辖
//由于求lowbit在补码的机器里可以O(1)获得,所以效率比较高
//最多是n个
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

// 关于这个BIT的add操作我有点没搞懂....
// 为什么是从lowbit开

// 1....10000
// idx - 2 ^ r + 1 ........idx个数

// 关键在于这个add, 不会漏掉吗......, ok 证明完毕... I complete understand

// 还有一个search for BIT, 关键在于我必须完全搞懂BIT中tree的概念,
// 然后就是BIT的suitable background, 然后具体的logn

// 操作和初始化, 前提是需要elements is non-negative

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