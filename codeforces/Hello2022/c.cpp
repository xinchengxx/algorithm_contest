#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n;
   	cin >> n;
    
    vector<int> p(n, -1);
  	for (int i = 0; i < n; i++) {
  		  if (p[i] != -1) {
            continue;
        }
        
        vector<int> a;
        
        int y = -1;
        while (true) {
           	cout << "? " << i + 1 << endl;
            int x;
            cin >> x;
            x--;
            if (y == -1) {
                y = x;
            } else if (x == y) {
                break;
            }
            a.push_back(x);
        }
        
        for (int j = 0; j < int(a.size()); j++) {
            p[a[j]] = a[(j + 1) % a.size()];
        }
  	}
    
    cout << "!";
    for (int i = 0; i < n; i++) {
        cout << " " << p[i] + 1;
    }
   	cout << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
   	cin >> t;

    while (t--) {
        solve();
    }
    
    return 0;
}
