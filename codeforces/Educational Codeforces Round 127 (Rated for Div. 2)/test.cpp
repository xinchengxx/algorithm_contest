#include <bits/stdc++.h>
using namespace std;

void print(int val) {
	vector<int> ans;
	while (val) {
		if (val & 1) {
			ans.push_back(1);
		} else {
			ans.push_back(0);
		}
		val >>= 1;
	}
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
} 

int main() {
	int val = 0;
	val |= (1 << 3);
	val |= (1 << 5);
	val |= (1 << 8);
	//print(val);


	// 好......
	for (int s = val; s; s = (s - 1) & val) {
		print(s);
	}
	return 0;
}