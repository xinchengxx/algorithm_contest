#include <bits/stdc++.h>
using namespace std;
using i64 = long long;


int t;

void solve() {
	// 好一个脑筋急转弯, 有的时候对情况分类也是一种重要的操作
	// 还有本题的回文串是什么, 注意只有两个的情况下的回文串
	int n;
	cin >> n;
	string s;
	cin >> s;
	int c = 0, i = 0;
	while (i < s.size()) {
		if (i + 1 < s.size() && s[i] == '(') {
			c++;
			i += 2;
			continue;
		} else {
			int j = i + 1;
			while (j < s.size() && s[j] != ')') {
				j++;
			}
			if (j == s.size()) 
				break;
			c++;
			i = j + 1;
		}
	}
	cout << c << " " << s.size() - i << endl; 
}

int main() {
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}