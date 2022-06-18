#include <iostream>
using namespace std;
#define MAX 1000006
// 区间加使用差分来进行计算,
// 对于不会改变的来说相当于一个套路,时间复杂度只需要遍历一遍数组
int n, m;
int a[MAX];
int df[MAX];
int di[MAX], l[MAX], r[MAX];
int need[MAX];
inline int read() {
    int x = 0;
    bool t = false;
    char ch = getchar();
    while ((ch < '0' || ch > '9') && ch != '-')
        ch = getchar();
    if (ch == '-')
        t = true, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    return t ? -x : x;
}
// 连续的固定区间加的一种方法,使用差分;
bool isok(int x) {
    // 表示前面
    memset(df, 0, sizeof(df));
    memset(need, 0, sizeof(need));
    for (int i = 1; i <= x; i++) {
        df[l[i]] += di[i];
        df[r[i] + 1] -= di[i];
    }
    for (int i = 1; i <= n; i++) {
        need[i] = need[i - 1] + df[i];

        if (need[i] > a[i])
            return false;
    }
    return true;
}

int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++) {
        a[i] = read();
    }
    for (int i = 1; i <= m; i++) {
        di[i] = read(), l[i] = read(), r[i] = read();
    }
    int b = 1, e = m;
    if (isok(m)) {
        printf("0");
        return 0;
    }
    while (b < e) {
        int mid = (b + e) >> 1;
        if (isok(mid)) {
            // 找的是第一个;
            b = mid + 1;
        } else {
            e = mid;
        }
    }
    printf("-1\n%d", b);
    return 0;
}