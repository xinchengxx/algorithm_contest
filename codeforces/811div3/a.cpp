#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
	int n, H, M;
	cin >> n >> H >> M;
	
	int ansh = INT_MAX, ansm = INT_MAX;
	for (int i = 0; i < n; i++) {
		int h, m;
		cin >> h >> m;
		if (h == H) {
			if (m < M) {
				h += 23;
				if (ansh == 23) {
					if (m + 60 - M < ansm) {
						ansm = m + 60 - M;
					}
				} else if (ansh > 23) {
					ansh = 23;
					ansm = m + 60 - M;
				}
				// 13 50
				// 13 49 13 + 24 - 1 - 13 
			} else {
				if (ansh == 0) {
					if (m - M < ansm) {
						ansm = m - M;
					}  
				} else if (ansh > 0) {
					ansh = 0;
					ansm = m - M;
				}
			}
		} else if (h < H) {
			if (m < M) {
				h += 23;
				if (ansh == h - H) {
					if (m + 60 - M < ansm) {
						ansm = m + 60 - M;
					}
				} else if (ansh > h - H) {
					ansh = h - H;
					ansm = m + 60 - M;
				}
			} else {
				h += 24;
				if (ansh == h - H) {
					if (m - M < ansm) {
						ansm = m - M;
					}
				} else if (ansh > h - H) {
					ansh = h - H;
					ansm = m - M;
				}
			}
		} else {
			if (m < M) {
				h -= 1;
				if (ansh == h - H) {
					if (m + 60 - M < ansm) {
						ansm = m + 60 - M;
					}
				} else if (ansh > h - H) {
					ansh = h - H;
					ansm = m + 60 - M;
				}
			} else {
				if (ansh == h - H) {
					if (m - M < ansm) {
						ansm = m - M;
					}
				} else if (ansh > h - H) {
					ansh = h - H;
					ansm = m - M;
				}
			}
		}
	}
	cout << ansh << " " << ansm << endl;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}