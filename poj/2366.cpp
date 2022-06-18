#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int mid_search(vector<int>& s, int val) {
	int l = 0, r = s.size() - 1;
	// 注意
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (s[mid] == val) {
			return mid;
		}
		if (s[mid] < val) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return -1;
}


int main() {
	vector<int> s1, s2;
	int n1, n2;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		int val;
		cin >> val;
		s1.push_back(val);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		int val;
		cin >> val;
		s2.push_back(val);
	}
	bool flag = false;
	for (int i = 0; i < n2; i++) {
		int left = 10000 - s2[i];
		if (mid_search(s1, left) != - 1) {
			flag = true;
			break;
		}		
 	}
 	if (flag) {
 		cout << "YES";
 	} else {
 		cout << "NO";
 	}
 	return 0;
}