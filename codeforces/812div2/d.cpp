#include <bits/stdc++.h>
using namespace std;

int query(int a, int b) {
	int ans;
	cout << "? " << a << " " << b << endl;
	cin >> ans;
	return ans;
}

void solve() {
	int n;
	cin >> n;

	vector<int> a(1 << n);
	iota(a.begin(), a.end(), 1);

	while (a.size() >= 4) {
		vector<int> b;
		for (int i = 0; i < a.size(); i += 4) {
			int q = query(a[i], a[i + 2]);
			if (q == 0) {
				int q2 = query(a[i + 1], a[i + 3]);
				if (q2 == 1) {
					b.push_back(a[i + 1]);
				} else {
					b.push_back(a[i + 3]);
				}
			} else if (q == 1) {
				int q2 = query(a[i], a[i + 3]);
				if (q2 == 1) {
					b.push_back(a[i]);
				} else {
					b.push_back(a[i + 3]);
				}
			} else {
				int q2 = query(a[i + 1], a[i + 2]);
				if (q2 == 1) {
					b.push_back(a[i + 1]);
				} else {
					b.push_back(a[i + 2]);
				}
			}
		}
		a = move(b);
	}

	if (a.size() == 2) {
		int q = query(a[0], a[1]);
		if (q == 2) swap(a[0], a[1]);
	}	

	cout << "! " << a[0] << endl;;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	while (t--) {
		solve();
	}

	return 0;
}