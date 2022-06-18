//两种做法
#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr){};
};

class Solution {
   public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int n, m;
        n = getLength(headA);
        m = getLength(headB);
        //长的先走
        if (n > m) {
            for (int i = 1; i <= n - m; i++)
                headA = headA->next;
        } else {
            for (int i = 1; i <= m - n; i++)
                headB = headB->next;
        }
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
    int getLength(ListNode* head) {
        int length = 1;
        while (head->next) {
            length++;
            head = head->next;
        }
        return length;
    }
    ListNode* getIntersectionNode_2(ListNode* headA, ListNode* headB) {
        unordered_set<ListNode*> s;
        while (headA->next) {
            s.emplace(headA);
            headA = headA->next;
        }
        while (headB->next) {
            if (s.count(headB) == 1)
                return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};