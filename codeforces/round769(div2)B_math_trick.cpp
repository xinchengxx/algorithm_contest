#include<bits/stdc++.h>
using namespace std;
int tt;
int getK(int n) {
	int k = 0;
	while (n) {
		n >>= 1;
		k++; 
	}
	return k;
}
int main() {
	cin >> tt;
	while (tt--) {
		int n;
		scanf("%d", &n);
		// 这是一个非常经典的题目;
		// 接下来求k; 
		int k = getK(n);
		for (int i = (1 << (k - 1)) - 1; i >= 0; i--) 
			printf("%d ",i);
		for (int i = (1 << k - 1); i < n; i++)
			printf("%d ",i);
		printf("\n");
	}
}

