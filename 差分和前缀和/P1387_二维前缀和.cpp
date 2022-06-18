//常用.
#include <iostream>
using namespace std;
// 二维前缀和;

#define MAX 105
int n, m;
int a[MAX][MAX], b[MAX][MAX];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            b[i][j] = b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] +
                      a[i][j];  // 二维前缀和;
        }
    int ans = 1;
    // 它是怎么暴力的
    int l = 2;
    while (l <= min(n, m)) {
        // 开始暴力枚举;
        for (int i = l; i <= n; i++)
            for (int j = l; j <= m; j++) {
                // 很容易想到的前缀和;
                int val = b[i][j] - b[i - l][j] - b[i][j - l] + b[i - l][j - l];
                if (val == l * l)
                    ans = max(ans, l);
            }
        l++;
    }
    printf("%d", ans);
    return 0;
}