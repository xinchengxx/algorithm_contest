#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

template <class Info, class Merge = std::plus<Info>>
struct SegmentTree {
    const int n;
    const Merge merge;
    std::vector<Info> info;
    // 仔细想想这个merge 默认是 std::plus, 底层调用其实是+, 是一种generic
    // type的写法，并且实际上是一个functor
    // 此处的Merge()实际上调用了其默认生成的构造函数4 << std::__lg(n),
    // 因为要开四倍大; 4 << std::__lg(n); // 注意这种写法;
    // std::__lg(n) return the highest bit 1 of n
    SegmentTree(int n) : n(n), merge(Merge()), info(4 << std::__lg(n)) {}
    SegmentTree(std::vector<Info> init) : SegmentTree(init.size()) {
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) { info[p] = merge(info[2 * p], info[2 * p + 1]); }
    // 注意是左闭右开, 所以终止条件一定是[r == l + 1]
    // [l, r)
    void modify(int p, int l, int r, int x, const Info& v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info& v) { modify(1, 0, n, p, v); }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        return merge(rangeQuery(2 * p, l, m, x, y),
                     rangeQuery(2 * p + 1, m, r, x, y));
    }
    Info rangeQuery(int l, int r) { return rangeQuery(1, 0, n, l, r); }
};

// 关键在于外部要实现operate+ 就可以自动实现std::plus
// 维护max的info
struct Max {
    int x;
    Max(int x = 0) : x(x) {}
};

// Max
Max operator+(const Max& a, const Max& b) {
    return std::max(a.x, b.x); // 这里存在一个implicity converstion
}


struct Plus {
    int x;
    Plus(int x = 0) : x(x) {}
};

Plus operator+(const Plus& a, const Plus& b) {
    return a.x + b.x;
}

