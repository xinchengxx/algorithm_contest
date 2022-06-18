#include <bits/stdc++.h>
using namespace std;

int t;

int a[32];
int ma = 1;
void init() {
	a[1] = 1;
	long long base = 1;
	while (base <= 1e9) {
		base = base * 3;
		a[++ma] = base;
	}
	// 1 < ma;
}

int main () {
	cin >> t;
	init();
	while (t--) {
		int n;
		cin >> n;
		if (n >= ma) {
			printf("No\n");
			continue;
		} else {
			printf("Yes\n");
			for (int i = 1; i <= n; i++)
				printf("%d ", a[i]);
			printf("\n");
		}
	}
	return 0;
}
