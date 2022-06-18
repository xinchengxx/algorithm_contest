#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<int> a(n), b(n);
	vector<int> cnt(n + 1), cnt2(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		cnt[a[i]]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}

	for (int j = n - 1, i = n - 1; j >= 0; ) {
		if (a[i] == b[j]) {
			cnt[b[j]]--;
			i--;
			j--;
		} else {
			if (cnt[a[i]] == 0) {
				i--;
				continue;
			}
			if (j == n - 1) {
				cout << "No\n";
				return;
			} else if (b[j] == b[j + 1]){
				if (cnt[b[j]] > 0) {
					cnt[b[j]]--;
					cnt2[b[j]]++;
					j--;
				} else {
					i--;
				}
			} else if (b[j] != b[j + 1]) {
				if (cnt2[a[i]] > 0) {
					cnt2[a[i]]--;
					i--;
				} else {
					cout << "No\n";
					return;
				}
			}
		}
	}
	cout << "Yes\n";
}


int main() {
	int t;
	cin >> t;

	while (t--) {
		solve();
	}
	return 0;
}

