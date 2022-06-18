#include<bits/stdc++.h>
using namespace std;
int t;
void solve() {
	int n;
	cin >> n;
	int tot = 0;
	vector<vector<int>> arr(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';
			if (arr[i][j] == 1)
				tot++;
		}
	}
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int nx = 0, ny = i;
		int t = 0;
		for (int j = 0; j < n; j++) {
			if (arr[nx][ny] == 1) t++;
			nx = (nx + 1) % n;
			ny = (ny + 1) % n;
		}
		mx = max(mx, t);
	} 
	cout << tot - mx + n - mx << endl;
}
int main() {
	
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
} 
