#include<bits/stdc++.h>
using namespace std;
int t;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		if (a == 0) {
			printf("1\n");
			continue;
		} else {
			printf("%d\n", a + 2 * b + 1);
		}
	}
	return 0;
}
