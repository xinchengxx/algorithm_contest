#include <iostream>
#include <vector>
using namespace std;
class Solution {
    // KMP的关键就在于思考不匹配的时候该回溯到哪一步,
    // 而在这个地方我们认为规定了一点 那就是nxt[0] = -1,
    // 有点好处，一是在匹配的时候如果发现了这个，就说明i无论如何都无法匹配到了,
    // 那么i++ 第二就是为nxt[1] = 0, 也是符合这个的特例，可以进行合并
    // 还一个核心就是i指针(即大字符串)永不后退
   public:
    int Strstr(string hackstr, string needle) {
        int n = needle.size(), m = hackstr.size();
        vector<int> nxt(n);
        nxt[0] = -1;
        int k = -1, j = 0;
        while (j < n) {
            if (k == -1 || needle[j] == needle[k]) {
                nxt[++j] = nxt[++k];
            } else {
                k = nxt[k];
            }
        }
        int i = 0;
        j = 0;
        while (i < m && j < n) {
            if (j == -1 || hackstr[i] == needle[j]) {
                i++;
                j++;
            } else {
                j = nxt[j];
            }
        }
        if (j == n)
            return i - n;
        return -1;
    }
};