#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int val) : val(val), next(nullptr){};
};

class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode *f = head, *s = head;
        while (1) {
            f = f->next;
            if (!f || !f->next)
                return nullptr;
            f = f->next;
            s = s->next;
            if (f == s) {
                f = head;
                while (f != s) {
                    f = f->next;
                    s = s->next;
                }
                return f;
            }
        }
    }
};