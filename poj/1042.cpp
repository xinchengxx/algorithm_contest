#include <iostream>
#include <string.h>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int fi[26], di[26], ti[26];
int cfi[26]; // 表示如今

// n <= 25;
struct node{
	int times[30];
	int tot;

	bool operator< (const node& that) {
		if (tot == that.tot) {
			for (int i = 1; i <= 25; i++) {
				if (times[i] != that.times[i]) {
					return times[i] < that.times[i];
				}
			}
		}
		return tot < that.tot;
	}
} a[26];


// 传入的是
struct comp {
	bool operator()(int x, int y) {
		if (cfi[x] == cfi[y]) {
			return x > y;
		}
		return cfi[x] < cfi[y];
	}
};

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (1) {
		cin >> n;
		if (n == 0) {
			break;
		}
		int h, minute;
		cin >> h;

		minute = 60 * h;
		memset(fi, 0, sizeof(fi));
		memset(di, 0, sizeof(di));
		memset(ti, 0, sizeof(ti)); // ctrl + shift + d复制上一行
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++) {
			cin >> fi[i];
		}

		for (int i = 1; i <= n; i++) {
			cin >> di[i];
		}

		for (int i = 1; i <= n - 1; i++) {
			cin >> ti[i];
		}
		
		// 枚举终点;
		for (int i = 1; i <= n; i++) {
			int rest = minute;
			for (int j = i - 1; j < i; j++) {
				rest -= ti[j] * 5;
			}
			rest = rest / 5; // 次数
			//cout << rest << endl;
			priority_queue<int, vector<int>, comp> pq;
			for (int j = 1; j <= i; j++) {
				cfi[j] = fi[j];
				pq.push(j);
			}
			while (rest--) {
				int cur = pq.top();
				//cout << cfi[cur] << endl;
				pq.pop();
				a[i].tot += cfi[cur];
				cfi[cur] -= min(di[cur], cfi[cur]);
				a[i].times[cur]++;
				pq.push(cur);
			}
		}
		sort(a + 1, a + 1 + n);

		for (int i = 1; i <= n; i++) {
			cout << a[n - 1].times[i] * 5 << " \n"[i == n];
		}
		cout << "Number of fish expected: " << a[n - 1].tot << endl;
	}
	return 0;
}
