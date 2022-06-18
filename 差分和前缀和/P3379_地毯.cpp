#include <iostream>
using namespace std;
#define MAX 1005
int n, m;
int a[MAX][MAX];
// 标记数组 a[][], b
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        for (int i = x1; i <= x2; i++) {
            a[i][y1] += 1;
            a[i][y2 + 1] -= 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] += a[i][j - 1];
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}