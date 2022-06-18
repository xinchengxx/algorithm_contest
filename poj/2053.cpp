#include <iostream>
#include <cmath>
#include <cstdio>
#include <map>
#include <string>

using namespace std;


// 使用map, 之后使用hash的做法可以研究一下
int main() {
	map<string, string> m;
	// 关键在于这个空行的读入...
	char a[24],b[12],c[12];
	while (gets(a) && a[0] != '\0') {
   		sscanf(a, "%s%s", &b, &c);
   		string t1 = b; 
   		string t2 = c;
   		m[t2] = t1;
  	}
 	while (gets(a) && a[0] != '\0') {
 		string t = a;
 		if (!m.count(t)) {
 			cout << "eh\n";
 		} else {
 			cout << m[t] << endl;
 		}
 	}
 	return 0;
}