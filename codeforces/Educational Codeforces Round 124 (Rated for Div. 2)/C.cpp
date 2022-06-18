#include <bits/stdc++.h>
using namespace std;

inline int read() {
	bool flag = false;
	int t = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		t = t * 10 + ch - '0';
		ch = getchar();
	}
	return flag == true ? -t : t;
} 


int t, n, val;
vector<int> a, b; 

// answer writes very gracefully
int bstCand(vector<int> &val, int tar) {
	// 返回pos;
	int pos = -1, dis = INT_MAX;
	for (int i = 0; i < val.size(); i++) {
		if (abs(val[i] - tar) < dis) {
			pos = i;
			dis = abs(val[i] - tar);
		}
	}
	return pos;
} 

void solve() {
	// 首先就是求bstcand
	long long ans = 1e14;
	
	vector<int> bs1 = {0, bstCand(b, a[0]), n - 1};    // 使用花括号表达式implicity调用constructor, a skill 
	vector<int> bs2 = {0, bstCand(b, a[n - 1]), n - 1};
	for (int val1 : bs1) {
		for (int val2 : bs2) {
			long long tot = 0;
			tot += abs(a[0] - b[val1]);
			tot += abs(a[n - 1] - b[val2]);
			if (val1 > 0 && val2 > 0) {
				tot += abs(b[0] - a[bstCand(a, b[0])]);
			}
			if (val1 < n - 1 && val2 < n - 1) {
				tot += abs(b[n - 1] - a[bstCand(a, b[n - 1])]);	
			}
			ans = min(ans, tot);
		}
	}
	cout << ans << endl;
}

int main() {
	t = read();
	while (t--) {
		n = read();
		a.clear(), b.clear();
		for (int i = 0; i < n; i++) {
			val = read();
			a.push_back(val);
		} 
		for (int i = 0; i < n; i++) {
			val = read();
			b.push_back(val);
		}
		solve();
	}
	return 0;
}
