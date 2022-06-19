#include <iostream>
#include <vector>
using namespace std;

class BIT {
public:
    BIT() : sums(1, 0) {}
    BIT(int n) : sums(n + 1, 0) {}
    
    void update(int index, int delta) {
        const int n = sums.size();
        while (index < n) {
            sums[index] += delta;
            index += _lowbit(index);
        }
    }
    
    int query(int i) {
        int sum = 0;
        while (i > 0) {
            sum += sums[i];
            i -= _lowbit(i);
        }
        return sum;
    }
    
private:
    vector<int> sums;
    
    int _lowbit(int x) {
        return x & (-x);
    }
};

class NumArray {
public:
    NumArray(vector<int>& nums):vec(move(nums)), bit(vec.size()) {
        const int n = vec.size();
        for (int i = 0; i < n; ++i) {
            bit.update(i + 1, vec[i]);
        }
    }
    
    void update(int index, int val) {
        bit.update(index + 1, val - vec[index]);
        vec[index] = val;
    }
    
    int sumRange(int left, int right) {
        return bit.query(right + 1) - bit.query(left);
    }
    
private:
    vector<int> vec;
    BIT bit;
};
