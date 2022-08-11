#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	i64 n, q, x;
	cin >> n >> q >> x;
	i64 sum = 0;
	vector<i64> w(n);
	vector<i64> pref(2 * n + 1);
	for (int i = 0; i < n; i++) {
		cin >> w[i];
		sum += w[i];
		pref[i + 1] = pref[i] + w[i];
	}
	for (int i = n + 1; i <= 2 * n; i++) {
		pref[i] = pref[i - 1] + w[i - n - 1];
	}
	i64 cnt = 0;
	cnt += 1ll * n * (x / sum);
	x = x % sum;
	vector<i64> cnts(n, cnt);
	vector<i64> nxt(n, -1);
	map<i64, i64> mp;
	// 使用binary search查找到哪为止;
	i64 t = 0, remain = 0; 
	if (x != 0) {
	for (int i = 0; i < n; i++) {
		i64 l = 0, r = n;
		i64 ans = r;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (pref[i + mid + 1] - pref[i] >= x) {
				ans = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		} 
		nxt[i] = (i + ans + 1) % n;
		cnts[i] += ans + 1;
	} } else {
		for (int i = 0; i < n; i++) {
			nxt[i] = (i + 1) % n;
		}
	}
	i64 st = 0, ti = 0;
	vector<i64> buck;
	while (!mp.count(st)) {
		mp.insert({st, ti});
		buck.push_back(cnts[st]);
		ti++;
		st = nxt[st];
	}
	t = ti - mp[st];
	i64 nst = 0;
	while (nst != st) {
		remain++;
		nst = nxt[nst];
	}
	for (int i = 1; i <= q; i++) {
		i64 k;
		cin >> k;
		k--;
		if (k < remain) {
			cout << buck[k] << "\n";
		} else {
			k -= remain;
			k %= t;
			cout << buck[k + remain] << "\n";
		}
	}
	return 0;
}