#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

const double pi = 3.1415926;

int t;

void solve(int i) {
	double x, y;
	cin >> x >> y;
	double square = (x * x + y * y) * pi / 2.0;
	int year = floor(square / 50.0) + 1;
	printf("Property %d: This property will begin eroding in year %d.\n", i, year);
}

int main() {
	cin >> t;
	int cnt = 1;
	while (t--) {
		solve(cnt++);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
