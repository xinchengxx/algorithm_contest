#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int dir[8][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};

int main() {
	int n;	
	cin >> n;

	vector<vector<int>> a(n, std::vector<int> (n));
	for (int i = 0; i < n; i++) {
		long long val;
		cin >> val;
		//cout << val << endl;
		for (int j = 0; j < n; j++) {
			a[i][n - 1 - j] = val % 10;
			val /= 10;
		}
	}
	
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int d = 0; d < 8; d++) {
				int curi = i, curj = j;
				long long digit = a[curi][curj];
				for (int k = 1; k <= n - 1; k++) {
					curi = ((curi + dir[d][0]) + n) % n;
					curj = ((curj + dir[d][1]) + n) % n;
					digit = digit * 10 + a[curi][curj];
					ans = max(ans, digit);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}