#include <iostream>
#include <vector>
using namespace std;

// 1.搜索某个特定的数(返回下标)
//  见模板

// 考虑一下类似的情况
// 比如说 4 5  搜 6
// 每次最多差1, 所以最后一定是l > r
// 并且考虑何时会出现这种l = r + 1
// 此时有l == r,表示
int binary_search(vector<int> a, int val) {
    int l = 0, r = a.size() - 1;
    // l <= r 是 <=
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] == val) {
            return mid;
        } else if (a[mid] < val) {
            l = mid + 1;
        } else if (a[mid] > val) {
            r = mid - 1;
        }
    }
    // 返回-1的情况
    return -1;
}

//但如果要搜索1 2 2 2 3 搜到2的左边界该如何做呢
int left_bound(vector<int> a, int val) {
    int n = a.size();
    int l = 0, r = n - 1;
    // 我会怎么写????
    // 我看一下之前我写的
    // 首先所有的都是
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] < val) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}