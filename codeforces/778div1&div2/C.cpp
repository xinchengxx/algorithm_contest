#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t;

int main() {
    cin >> t;
    while (t--) {
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
            if (x < *--s1.end())
                break;
            s2.erase(--s2.end());
            if (s1.find(x) != s1.end())
                s1.erase(
                    s1.find(x));  // ���ص���iterator, ע��multiset��erase����
            else {
                s2.insert(x / 2);
                s2.insert((x + 1) / 2);  // ע��ذ���Ĳ���
            }
        }
        if (s1.empty())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
