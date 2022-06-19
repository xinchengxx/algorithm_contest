//本题是一个随机算法
// 成为蓄水池抽样算法,
// 详细思想就是i个数保留的概率为1/i,这样n个数每个数被抽到的概率都是1/n;
#include <cstdlib>
#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
   public:
    Solution(ListNode* head) { this->head = head; }

    int getRandom() {
        int cnt = 0;
        int val;
        ListNode* newHead = this->head;
        while (newHead) {
            cnt++;
            if (rand() % cnt == 0) {
                val = newHead->val;
            }
            newHead = newHead->next;
        }
        return val;
    }
    ListNode* head;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */