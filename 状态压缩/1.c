#include <stdio.h>
int cnt = 0;
int main() {
    if (cnt == 5) {
        return 0;
    }
    cnt++;
    int a = main();
    printf("%d %d\n", a, cnt++);
    return 0;
}