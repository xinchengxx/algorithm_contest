#include <stdio.h>
#include <stdlib.h>
using namespace std;
char color[][4] = {"红", "白", "蓝", "绿", "黄", "黑", "白"};
void find(int m, int n) {
    int* set = new int[m];
    int i, postion;
    for (i = 0; i < m; i++)
        set[i] = i + 1;
    for (i = 0; i < n; i++)
        printf("%s ", color[set[i] - 1]);
    putchar('\n');
    postion = n - 1;
    while (1) {
        if (set[n - 1] == m)
            postion--;
        else
            postion = n - 1;
        set[postion]++;
        for (i = postion + 1; i < n; i++) {
            set[i] = set[i - 1] + 1;
        }
        for (i = 0; i < n; i++)
            printf("%s ", color[set[i] - 1]);
        putchar('\n');
        if (set[0] >= m - n + 1)
            break;
    }
}
int main() {
    find(6, 3);
    find(6, 4);
    return 0;
}