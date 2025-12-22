#include "../include/list_node.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int temp = 0;
        ListNode dummy;
        ListNode *p = &dummy;
        
        while (l1 || l2 || temp > 0) {
            int a = 0, b = 0;
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            }
            
            int sum = a + b + temp;
            p->next = new ListNode(sum % 10);
            p = p->next;
            temp = sum / 10;

        }
        return dummy.next;
    }
};

#include <iostream>
int main() {
    std::vector<int> v1 = {3,6,9};
    std::vector<int> v2 = {3,4,5,6,7};
    ListNode* l1 = ListTools::create(v1);
    ListNode* l2 = ListTools::create(v2);
    ListNode* p = l1;
    ListNode* q = l2;
    Solution solver;
    auto res = solver.addTwoNumbers(l1, l2);
    ListTools::print(res);
    ListNode::freeList(l1);
    ListNode::freeList(l2);
    ListNode::freeList(res);
    return 0;
}

