#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool is_prime(int t) {
	for (int i = 2; i * i <= t; i++) {
		if (t % i == 0) 
			return false;
	}
	return true;
}


int main() {	
	i64 n;
	cin >> n;

	i64 ret = 0;
	vector<int> p;
	auto bi_search = [&](int val) {
		//当前的p;
		int l = 0, r = p.size() - 1;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (1ll * p[mid] * pow(val, 3) <= n) {
				ans = mid;
				l = mid + 1;
			} else {
				r = mid - 1;
			}
		}
		return ans;
	};


	for (int i = 2; i <= 1e6; i++) {
		if (is_prime(i)) {
			//cout << 1 << endl;
			int idx = bi_search(i);
			ret += (idx + 1);
			p.push_back(i);
		}
	}
	cout << ret;
	return 0;
}