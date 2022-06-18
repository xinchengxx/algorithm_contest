#include <iostream>
#include <vector>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}	
	int ans = 0;

	vector<vector<int>>	pre(n, vector<int>(n + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			pre[i][j + 1] = pre[i][j] + a[i][j];
		}
	}

	vector<vector<vector<int>>> f(n, vector<vector<int>>(n, vector<int>(n)));
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			f[0][i][j] = pre[0][j + 1] - pre[0][i]; // i.......j
			ans = max(ans, f[0][i][j]);
		}
	}
	for (int k = 1; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
			int sum = pre[k][j + 1] - pre[k][i];
			f[k][i][j] = max(f[k - 1][i][j] + sum, sum);
			ans = max(ans, f[k][i][j]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}