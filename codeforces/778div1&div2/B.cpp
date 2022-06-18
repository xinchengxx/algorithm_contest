#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        unordered_set<char> st;
        int start = s.size() - 1;
        for (int k = s.size() - 1; k >= 0; k--) {
            if (st.count(s[k]))
                continue;
            st.insert(s[k]);
            start = k;
        }
        cout << s.substr(start, s.size() - start) << endl;
    }
}
