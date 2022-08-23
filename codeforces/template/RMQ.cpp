#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// 本题需要学习一下jiangly 的RMQ的template

// 关键在于std::min本质可以+ cmp的.. cmp是一个functor即重载了()的类实例化对象
// 还有就是std::assign的方法....就是这么简单和朴素...不是resize
template <class T, class Cmp = std::less<T>>
struct RMQ {
    const int n;
    const Cmp cmp;
    std::vector<std::vector<T>> a;
    RMQ(const std::vector<T>& init) : n(init.size()), cmp(Cmp()) {
        int lg = std::__lg(n);
        a.assign(n, std::vector<T>(lg + 1));
        for (int j = 0; j <= lg; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                a[i][j] =
                    (j == 0 ? init[i]
                            : std::min(a[i][j - 1],
                                       a[i + (1 << (j - 1))][j - 1], cmp));
            }
        }
    }
    T rangeMin(int l, int r) {
        int k = std::__lg(r - l);
        return std::min(a[l][k], a[r - (1 << k)][k], cmp);
    }
};

// 本质上是...
template <class T, class Cmp = std::less<T>>
struct MyRMQ {
    const int n;
    const Cmp cmp;  // functor
    vector<vector<T>> a;

    MyRMQ(const vector<T>& init) : n(init.size()), cmp(Cmp()) {
        int lg = std::__lg(n);           // __lg
        a.assign(n, vector<T>(lg + 1));  // 注意这是lg + 1;
        for (int j = 0; j <= lg; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                // 还有一点注意.. 三目运算符优先级比= 要低
                a[i][j] = (j == 0 ? init[i]
                                  : min(a[i][j - 1], a[i + (1 << j - 1)][j - 1],
                                        cmp));
            }
        }
    }

    T rangeMin(int l, int r) {
        int k = std::__lg(r - l);
        return min(a[l][k], a[r - (1 << k)][k], cmp);
    }
};
