#include <bits/stdc++.h>
using namespace std;

int t, n;
vector<int> a(105);

int main() {
    cin >> t;
    while (t--) {
        int ans = 0;
        a.clear();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int start = 1;
        while (start <= n && a[start] == 1)
            start++;
        if (start == n + 1) {
            cout << 0 << endl;
            continue;
        }
        int end = n;
        while (end >= 1 && a[end] == 1)
            end--;
        cout << end - start + 2 << endl;
    }
}
