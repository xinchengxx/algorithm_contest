#include <bits/stdc++.h>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;

	int ans = 0;
	int R, C;
	cin >> R >> C;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (abs(i - R) + abs(j - C) == 1) {
				ans++;
			}
		}
	}
	cout << ans;
	return 0;
}