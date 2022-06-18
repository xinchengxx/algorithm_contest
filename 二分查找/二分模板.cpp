#include <iostream>
#include <vector>
using namespace std;

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

int left_bound(vector<int> a, int val) {
    int n = a.size();
    int l = 0, r = n - 1;

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