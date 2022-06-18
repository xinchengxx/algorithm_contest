#include <bits/stdc++.h>
using namespace std;




int main() {
	int n, q;
	cin >> n >> q;

	vector<int> a(n);
	std::iota(a.begin(), a.end(), 1);

	vector<int> pos(n + 1);
	std::iota(pos.begin(), pos.end(), -1);




	vector<int> x(q);
	for (int i = 0; i < q; i++) {
		cin >> x[i];

		int cur = pos[x[i]];
		if (cur == n - 1) {
			//cout << 1111 << endl;
			pos[a[n - 2]] = n - 1;
			pos[a[n - 1]] = n - 2;
			swap(a[n - 1], a[n - 2]);
		} else {
			pos[a[cur + 1]] = cur;
			pos[a[cur]] = cur + 1;
			swap(a[cur], a[cur + 1]); 
		}
		//cout << i << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " \n"[i == n - 1];
	}

	return 0;
}