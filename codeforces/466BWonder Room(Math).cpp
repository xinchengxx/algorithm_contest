#include<bits/stdc++.h>
using namespace std;
long long a, b;

long long n;
// 本题的关键是用了一个Trick
// 实际上本质是BRUTE FORCE
// 就是assume a <= b 的情况下 newa <= newb (这个可以自己考虑一下)
// 那么只需要考虑newa <= sqrt(6*n)的情况了, 并且计算newb
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    if (6 * n <= a * b)
        cout << a * b << "\n" << a << " " << b << "\n";
    else {
        bool flag = 0; // 表示交换过 
        if (a > b)
        {
            swap(a, b);
            flag = 1;
        }
        
        long long SQ = 1e18, a1, b1, tmpb;
        for(long long i = a; i*i <= 6*n; ++i) {
            tmpb = 6*n / i;
            if (tmpb * i < 6*n) tmpb++;
            
            if (tmpb < b) continue;
            
            if (tmpb * i < SQ) {
                SQ = tmpb * i;
                a1 = i;
                b1 = tmpb;
            }
        }
        
        if (flag)
            swap(a1, b1);
        
        cout << SQ << "\n" << a1 << " " << b1 << "\n";
    }
 
    return 0;
}
