#include<bits/stdc++.h>
using namespace std;
#define ll long long 

int t;

int main() {
	cin >> t;
	// 本题的模拟可以好好想想, 是怎么使用的, 以及关于set的iterator重载了-- ++, 操作 
	while (t--) {
		// multiset可以重复元素并且自动logn排序 
		multiset<ll> s1, s2;
		int n;
		scanf("%d", &n);
		ll sum = 0;
		for (int i = 1; i <= n; i++) {
			int val;
			scanf("%d", &val);
			s1.insert(val); 
			sum += val; 
		}
		s2.insert(sum);
		while (!s1.empty()) {
			 ll x = *--s2.end();
			 if (x < *--s1.end()) break;
			 s2.erase(--s2.end());
			 if (s1.find(x) != s1.end())
			 	s1.erase(s1.find(x)); // 返回的是iterator, 注意multiset的erase操作 
		     else {
		     	s2.insert(x / 2);
		     	s2.insert((x + 1) / 2); // 注意地板除的操作 
			 } 
		}
		if (s1.empty()) printf("Yes\n");
		else	printf("No\n"); 
	}
	return 0;
}
