#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;

	cin >> n >> a >> b;


	vector<vector<int>> t(n, vector<int>(n));
	t[0][0] = 0; // 0表示白色;
	for (int i = 1; i < n; i++) {
		if (t[0][i - 1] == 0) {
			t[0][i] = 1;
		} else {
			t[0][i] = 0;
		}
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (t[i - 1][j] == 0) {
				t[i][j] = 1;
			} else {
				t[i][j] = 0;
			}
		}
	}

	//cout << 1 << endl;
	vector<vector<char>> ans(n * a, vector<char>(n * b));
	for (int i = 0; i < n * a; i += a) {
		for (int j = 0; j < n * b; j += b) {
			if (t[i / a][j / b] == 0) {
				for (int k1 = i; k1 < i + a; k1++) {
					for (int k2 = j; k2 < j + b; k2++) {
						ans[k1][k2] = '.';
					}
				}
			} else {
				for (int k1 = i; k1 < i + a; k1++) {
					for (int k2 = j; k2 < j + b; k2++) {
						ans[k1][k2] = '#';
					}
				}
			}
		} 
	}

	for (int i = 0; i < n * a; i++) {
		for (int j = 0; j < n * b; j++) {
			cout << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}