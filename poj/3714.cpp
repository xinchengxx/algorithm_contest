#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;
int t, n;


typedef long long ll;
const int N = 2e5 + 10;
struct Point {
	
	int x, y; 
	int flag;
} arr[N];

int c[N];

// 本题被卡了cin, vector的时间常数

// 类似于平面最近点对

inline int read() {
	bool flag = false;
	int tot = 0;
	char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') flag = true;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		tot = tot * 10 + ch - '0';
		ch = getchar();
	}
	return flag == true ? -tot : tot;
}

const double inf = 2000000000;

inline double getdist(int x1, int y1, int x2, int y2) {
	ll tot = (ll)(x1 - x2) * (ll)(x1 - x2) * 1ll + (ll)(y1 - y2) * (ll) (y1 - y2) *1ll;
	return sqrt(double(tot));
}

bool cmpx(const Point &p1, const Point &p2) {
	return p1.x < p2.x;
}
 
bool cmp(int p1, int p2) {
	return arr[p1].y < arr[p2].y;
}


double solve(int l, int r) {
	if (l == r)
		return inf;
	// 这个模板还是记一下吧, 边界实际上是两个....
	if (r == l + 1) {
		if (arr[l].flag == arr[r].flag)
			return inf;
		return getdist(arr[l].x, arr[l].y, arr[r].x, arr[r].y);
	}
	int mid = (l + r) >> 1;
	double d = inf;
	d = min(d, solve(l, mid));
	d = min(d, solve(mid + 1, r));
	int w = arr[mid].x;
	int cnt = 1;
	for (int i = l; i <= r; i++) {
		if (abs(arr[i].x - w) <= d) {
			c[cnt++] = i;
		}
	}
	sort(c + 1, c + cnt, cmp);
	int low = 1, high = 2;
	while (low < cnt) { 
		while (high < cnt && abs(arr[high].y - arr[low].y) <= d) {
			high++;
		}
		for (int i = low + 1; i < high; i++) {
			if (arr[low].flag == arr[i].flag) continue;
			d = min(d, getdist(arr[low].x, arr[low].y, arr[i].x, arr[i].y));
		}
		low++;
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	t = read();
	while (t--) {
		int n;
		n = read();
		for (int i = 1; i <= 2 * n; i++) {
			arr[i].x = read(), arr[i].y = read();
			if (i <= n) {
				arr[i].flag = 1;
			} else {
				arr[i].flag = 0;
			}
		}
		sort(arr + 1, arr + 1 + 2 * n, cmpx);
		double ans = solve(1, 2 * n);
		printf("%.3lf\n", ans);		
	}
}