struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}

    //静态方法传引用释放链表并置空头指针；
    static void freeList(ListNode*& head) {
        ListNode *current = head;
        while(current) {
            ListNode* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }

    
};


#include <vector>
#include <iostream>

namespace ListTools {
    // factory
    inline ListNode* create(std::vector<int>& values) {
        if (values.empty()) return nullptr;
        
        ListNode* head = new ListNode(values[0]);
        ListNode* curr = head;

        for (size_t i = 1; i < values.size(); ++i) {
            curr->next = new ListNode(values[i]);
            curr = curr->next;
        }
        return head;
    }
    // tool
    inline void print(ListNode* head) {
        while (head) {
            std::cout << head->val;
            if (head->next) std::cout << "->";
            head = head->next;
        }
    }
}