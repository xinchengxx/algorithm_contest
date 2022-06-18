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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //首先弄一个dummy node
        ListNode* dummy_node = new ListNode();
        dummy_node->next = head;
        ListNode *fast_ptr = dummy_node, *slow_ptr = dummy_node;  //快慢指针
        ListNode* last;
        for (int i = 1; i <= n - 1; i++)
            fast_ptr = fast_ptr->next;
        while (fast_ptr->next) {
            last = slow_ptr;
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
        last->next = slow_ptr->next;
        delete slow_ptr;
        return dummy_node->next;
    }
};