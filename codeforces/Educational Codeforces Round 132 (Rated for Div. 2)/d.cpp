#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template<class T, class Cmp = less<T>>
struct RMQ {
    int n;
    vector<vector<T>> a;
    Cmp cmp;

    RMQ(vector<int>& init): n(init.size()), cmp(Cmp()) {
        int lg = __lg(n);
        a.assign(n, vector<T>(lg + 1));
        for (int j = 0; j <= lg; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                a[i][j] = (j == 0 ? init[i] : min(a[i][j - 1], a[i + (1 << j - 1)][j - 1], cmp));
            }
        }
    } 
    T rangeMin(int l, int r) {
        int k = __lg(r - l);
        return min(a[l][k], a[r - (1 << k)][k], cmp);
    }
};


int main() {
    // 注意这两行还是要的...
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (int i = 0; i < m; i++) {
		cin >> a[i];
	}
	int q;
	cin >> q;

	// 区间上最值的维护, RMQ;
	RMQ<int, greater<>> rmq(a);

	// 思路非常简单, 关键在于维护区间上的最值,, 使用RMQ
	while (q--) {
		int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        ys--;
        yf--;
        if (ys > yf) {
           swap(xs, xf);
           swap(ys, yf);
        }
        if ((xs - xf) % k != 0 || (ys - yf) % k != 0) {
            cout << "NO\n";
            continue;
        }
        int lim = xs + (n - xs) / k * k;

        // 注意这个rmp模板的rangeMin是一个左闭右开的区间。。。
        // 还有关于cpp的lg需要了解一下呢...
        if (rmq.rangeMin(ys, yf + 1) < lim) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
	}
	return 0;
}
