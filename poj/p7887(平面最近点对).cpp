#include <bits/stdc++.h>

using namespace std;

// 这是一个非常好的问题, 关于时间复杂度的证明


// f(n) = 2 * f(n / 2) + nlogn = nlogn^2

typedef long long ll;
struct Point {
	Point(int x, int y) : x(x), y(y) {}
	int x, y;
};

bool cmpx(const Point &p1, const Point &p2) {
	return p1.x < p2.x;
}

bool cmpy(const Point &p1, const Point &p2) {
	return p1.y < p2.y;
}

const ll inf = 800000000000000 + 10;

typedef vector<Point>::iterator Iter;
ll getdis(const Point &p1, const Point &p2) {
	// 主要是乘法顺序的问题
	return (ll)(p1.x - p2.x) * (ll)(p1.x - p2.x) * 1ll + (ll)(p1.y - p2.y) * (ll)(p1.y - p2.y) * 1ll;
}

ll solve(Iter l, Iter r) {
	// vector的迭代器重载了+ -, ++, --
	if (r == l + 1) {
		return inf;
	}
	ll d = inf;
	Iter mid = l + (r - l) / 2; //Iter 居然可以这么运算
	d = min(solve(l, mid), d);
	d = min(solve(mid, r), d);
	vector<Point> q;
	int w = mid->x;
	for (Iter it = l; it < r; ++it) {
		if (abs(it->x - w) <= sqrt(d)) {
			q.push_back(*it);
		}
	}
	// 关于本题的时间复杂度的分析,,, 以及关于主定理
	sort(q.begin(), q.end(), cmpy); 
	Iter low = q.begin(), high = q.begin() + 1;
	while (low != q.end()) {
		while (high != q.end() && abs(high->y - low->y) <= sqrt(d)) {
			++high;
		}
		for (Iter k = low + 1; k < high; ++k) {
			d = min(d, getdis(*low, *k));
		}
		++low;
	}
	return d;
}



int main() {
	vector<Point> p;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		p.push_back({x, y});
	}
	sort(p.begin(), p.end(), cmpx);

	ll ans = solve(p.begin(), p.end());
	cout << ans << endl;
	return 0;
}