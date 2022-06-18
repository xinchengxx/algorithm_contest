#include <bits/stdc++.h>
using namespace std;



int main() {
	int n;
	cin >> n;

	vector<int> a(n), b(n);
	int cnt1, cnt2;
	set<int> st;
	vector<int> s1, s2; // 

	vector<bool> vis(n);

	vector<int> num1(n), num2(n);
	// 判断两个set是不是相同的;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!st.count(a[i])) {
			s1.push_back(a[i]);
			cnt1++;
			st.insert(a[i]);
		}

		num1[i] = st.size();
	}
	st.clear();

	for (int i = 0; i < n; i++) {
		cin >> b[i];
		if (!st.count(b[i])) {
			s2.push_back(b[i]);
			cnt2++;
			st.insert(b[i]);
		}

		num2[i] = st.size(); // 
	}
	//cout << 1 << endl;
	st.clear();

	for (int i = 0; i < min(cnt1, cnt2); i++) {
		if (!st.count(s1[i])) {
			st.insert(s1[i]);
		} else {
			st.erase(s1[i]);
		}

		if (!st.count(s2[i])) {
			st.insert(s2[i]);
		} else {
			st.erase(s2[i]);
		}
		if (st.empty())
			vis[i] = true;
	}
	//cout << 1 << endl;
	int q;
	cin >> q;

	while (q--) {
		int xx, yy;
		cin >> xx >> yy;
		xx--, yy--;
		if (num1[xx] == num2[yy] && vis[num1[xx] - 1] == true) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}

	return 0;
}