#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
int a[500000 + 10];
int n;
set<int> se;
//算是一个很经典的题目了
vector<vector<int>> s(500000 + 10);
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s[a[i]].push_back(i);
        se.insert(a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] && !a[i - 1])
            ans++;
    }  // 统计非零段的个数
    // 它这个思路巧妙之处在于哪里呢???相当于枚举
    set<int>::iterator it = se.begin();
    if (*it == 0)
        it++;
    // 学习一下set迭代器的写法;
    int ret = ans;
    while (it != se.end()) {
        int num = *it;
        // 然后修改为0,可以逐次修改是最关键的;
        for (int i = 0; i < s[num].size(); i++) {
            int id = s[num][i];
            a[id] = 0;
            if (a[id - 1] && a[id + 1])
                ans++;
            if (!a[id - 1] && !a[id + 1])
                ans--;
        }
        ret = max(ret, ans);
        it++;
    }
    printf("%d\n", ret);
    return 0;
}