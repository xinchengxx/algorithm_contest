#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int m, n, t[1001], i, sum;
    cin >> m;
    while(m--)
    {
        cin >> n;
        sum = 0;
        for(i = 0; i < n; i++)
            cin >> t[i];
        sort(t, t + n);
        for(i = n - 1; i > 2; i -= 2)
            if(t[0] + 2 * t[1] + t[i] > 2 * t[0] + t[i - 1] + t[i])
                sum += 2 * t[0] + t[i - 1] + t[i];
            else sum += t[0] + 2 * t[1] + t[i];
            if(i == 2) sum += t[0] + t[1] + t[2];
            else if(i == 1) sum += t[1];
            else sum += t[0];
            cout << sum << endl;
    }
    return 0;
}