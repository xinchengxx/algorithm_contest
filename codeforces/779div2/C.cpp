#include <bits/stdc++.h>
using namespace std;

int t;

inline int read() {
	bool flag = false; int tot = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		tot = tot * 10 + ch - '0';
		ch = getchar();
	}
	return flag == true ? -tot : tot;
}

int main() {
	t = read();
	while (t--) {
		int n = read();
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) {
			a[i] = read();
		}
		vector<int> b(n + 1);
		int i = 1;
		while (i <= n && a[i] != 1) i++;
		if (i == n + 1) {
			printf("NO\n");
			continue;
		} else {
			for (int j = 1; j <= n; j++) {
				b[j] = a[i];
				i++;
				if (i == n + 1) {
					i = 1;
				}
			}
			int k;
			for (k = 2; k <= n; k++) {
				if (b[k] == 1) {
					printf("NO\n");
					break;
				}
				if (b[k] - b[k - 1] > 1) {
					printf("NO\n");
					break;
				}
			}
			if (k == n + 1) {
				printf("YES\n");
			}
		}
	}
	return 0;
}
