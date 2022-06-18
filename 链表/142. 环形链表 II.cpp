#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int val) : val(val), next(nullptr){};
};

//学习一下快慢指针的做法
//首先设无环部分长为a,有环部分长为b
//那么初次相遇时快指针走了f=2s f-s=nb  f=2nb s=nb 故再走a步即可
//让f回到head 第二次相遇时即走了a步
class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        // unordered_set<ListNode*> s;
        // while(1){
        //     if(head==nullptr)
        //         return nullptr;
        //     if(s.count(head))
        //         return head;
        //     s.emplace(head);
        //     head=head->next;
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