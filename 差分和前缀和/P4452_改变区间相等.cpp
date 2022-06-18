#include <iostream>
using namespace std;
#define MAX 1005
int n, m;
int df[100000 + 5];
int a[100000 + 5];

int main() {
    cin >> n;
    int pos = 0, neg = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        df[i] = a[i] - a[i - 1];
        if (i >= 2) {
            if (df[i] > 0) {
                pos += df[i];
            } else {
                neg -= df[i];
            }
        }
    }
    if (pos < neg) {
        swap(pos, neg);
    }
    printf("%d\n%d", pos, pos - neg + 1);
    return 0;
}