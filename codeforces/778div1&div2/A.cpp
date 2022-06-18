#include<bits/stdc++.h>
using namespace std;
int t;
void solve() {
	int x, y;
	cin >> x >> y;
	if (x == 0 && y == 0) {
		printf("0\n");
		return;
	}
	int tot = x * x + y * y;
	int i = 1;
	while (i * i < tot) i++;
	if (i * i == tot) {
		printf("1\n");
		return;
	}
	printf("2\n");
}
int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
