#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
using namespace std;

int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

int main() {
	int num = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			char c;
			cin >> c;
			int k = i * 4 + j;
			// b 是 1
			if (c == 'b') {
				num = num | (1 << k);
			} else {
				num = num & ~(1 << k);
			}
		}
	set<int> st;
	st.insert(num);
	queue<pair<int, int>> q;
	q.push(make_pair(num, 0));
	while (!q.empty()) {
		// 暴力判断每一个翻还是不翻;
		pair<int, int> it = q.front();
		int cur = it.first, id = it.second;
		q.pop();
		if (cur == 0 || cur == (1 << 16) - 1) {
			printf("%d", id);
			return 0;
		}
		for (int k = 0; k < 16; k++) {
			int tmp = cur;
			int i = k / 4, j = k % 4;
			tmp = tmp ^ (1 << k); // flip
			for (int t = 0; t < 4; t++) {
				int ni = i + dir[t][0];
				int nj = j + dir[t][1];
				if (ni >= 0 && ni < 4 && nj >= 0 && nj < 4) {
					int nk = ni * 4 + nj;
					tmp = tmp ^ (1 << nk);
				}
			}
			if (!st.count(tmp)) {
				st.insert(tmp);
				q.push(make_pair(tmp, id + 1));
			}
		}
	}
	printf("Impossible");
	return 0;
}	