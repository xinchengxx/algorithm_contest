#include <bits/stdc++.h>

using namespace std;

#define ll long long
typedef vector<ll> vll;
#define io                            \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

int main()
{
    io;
    ll tc;
    cin >> tc;
    while (tc--)
    {
        ll n;
        cin >> n;
        vll s(n), p(n);
        for (ll i = 0; i < n; ++i)
            cin >> s[i];

        ll l = 0, r = 0;
        bool ans = true;
        for (ll i = 0; i < n; ++i)
            p[i] = i + 1;

        while (r < n)
        {
            while (r < n - 1 and s[r] == s[r + 1]) // get range [l,r] with equal values
                ++r;
            if (l == r)
                ans = false;
            else
                rotate(p.begin() + l, p.begin() + r, p.begin() + r + 1); // rotate right in range [l,r]
            l = r + 1;
            ++r;
        }
        if (ans)
        {
            for (auto &x : p)
                cout << x << " ";
            cout << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}