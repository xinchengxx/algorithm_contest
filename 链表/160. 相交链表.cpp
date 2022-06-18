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
    //类似于LCA最近公共祖先的方法
    //下面还有一种hash_set的做法
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
        //我很奇怪啊,这个明明是自定义数据类型,咋还能用hash_set呢;
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