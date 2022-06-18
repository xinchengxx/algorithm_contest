#include<bits/stdc++.h>
using namespace std;
int t;
int main() {
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string str;
		cin >> str;
		if (str.size() >= 3) {
			printf("NO\n");
			continue;
		}
		if (str == "00" || str == "11") {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
	}
	return 0;
} 
