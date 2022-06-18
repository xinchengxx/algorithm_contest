#include <iostream>
using namespace std;

// 使用前缀和可以轻松的维护区间和;
#define MAX 50006
int n;
int a[MAX], sum[MAX];
int mi[7], ma[7];
int main() {
    cin >> n;
    for (int i = 1; i <= 6; i++) {
        mi[i] = INT_MAX;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sum[i] = (sum[i - 1] + a[i]) % 7;
        mi[sum[i]] = min(mi[sum[i]], i);
        ma[sum[i]] = max(ma[sum[i]], i);
    }
    int ans = 0;
    for (int i = 0; i < 7; i++) {
        if (ma[i] < mi[i])
            continue;
        ans = max(ans, ma[i] - mi[i]);
    }
    printf("%d", ans);
    return 0;
}