#include <bits/stdc++.h>
int t;

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> t;

    while (t--) {
        int n, c;
        std::cin >> n >> c;
        std::vector<int> arr(n + 1), pref(c + 1);
        for (int i = 1; i <= n; i++) {
            std::cin >> arr[i];
            pref[arr[i]]++;
        }
        for (int i = 1; i <= c; i++) {
            pref[i] += pref[i - 1];
        }
        bool flag = true;

        for (int i = 1; i <= c; i++) {
            if (pref[i] == pref[i - 1])
                continue;

            for (int j = i; j <= c; j += i) {
                int x = pref[std::min(j + i - 1, c)] - pref[j - 1];  //
                if (x == 0)
                    continue;
                x = j / i;
                if (pref[x] == pref[x - 1]) {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (flag)
            std::cout << "Yes\n";
        else
            std::cout << "No\n";
    }

    return 0;
}
