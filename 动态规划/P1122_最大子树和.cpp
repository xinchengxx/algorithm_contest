
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 16000 + 10;
int n;
int a[maxn], dp[maxn];
vector<int> E[maxn];

void work(int s, int fa) {
    dp[s] = a[s];
    for (int i = 0; i < E[s].size(); i++) {
        int v = E[s][i];
        if (v != fa) {
            work(v, s);
            dp[s] += max(dp[v], 0);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        E[a].push_back(b);
        E[b].push_back(a);
    }
    // 可以任取一个为根节点;
    work(1, 0);
    int ma = INT_MIN;
    for (int i = 1; i <= n; i++) {
        ma = max(ma, dp[i]);
    }
    printf("%d", ma);
    return 0;
}