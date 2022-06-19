#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        const int k = (n1 + n2 + 1) >> 1;
        int left = 0;
        int right = n1;
        while (left < right) {
            const int m1 = left + ((right - left) >> 1), m2 = k - m1;
            if (nums1[m1] < nums2[m2-1])
                left = m1 + 1;
            else
                right = m1;
        }
        const int m1 = left, m2 = k - left, c1 = max(
            m1 <= 0 ? -1e6-1:nums1[m1-1],
            m2 <= 0 ? -1e6-1:nums2[m2-1]
        );
        if ((n1 + n2) & 1)
            return c1;
        const int c2 = min(m1 >= n1 ? 1e6+1:nums1[m1],
                        m2 >= n2 ? 1e6+1:nums2[m2]);
        return (c1 + c2) * 0.5;
    }
};