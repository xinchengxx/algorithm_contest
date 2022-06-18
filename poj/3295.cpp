#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool arr[5]; //表示p, q, r, s, t 
string s;
int idx = 0;

bool check() {
	char c = s[idx];
	idx++;
	if (c == 'p') return arr[0];
	if (c == 'q') return arr[1];
	if (c == 'r') return arr[2];
	if (c == 's') return arr[3];
	if (c == 't') return arr[4];
	if (c == 'N') {
		bool flag = check();
		return 1 - flag;
	}
	bool flag1 = check(), flag2 = check();
	if (c == 'K') return flag1 && flag2;
	if (c == 'A') return flag1 || flag2;
	if (c == 'C') {
		if (flag1 == true && flag2 == false) 
			return false;
		return true;
	}
	else 
		return flag1 == flag2;
}

int main() {
	while (cin >> s) {
		if (s == "0")
			break;
		// 暴力枚举
		bool flag = false;
		for (int i = 0; i < 32; i++) {
			for (int k = 0; k < 5; k++) {
				if ((1 << k) & i) {
					arr[k] = true;
				} else {
					arr[k] = false;
				}
			}
			idx = 0;
			if (!check()) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "not" << endl;
		} else {
			cout << "tautology" << endl;
		}
	}
}