/**
 * 142. Linked List Cycle II
 * Medium
 * 快慢指针找环入口
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // 第一步：快慢指针判断是否有环，找到相遇点
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                // 第二步：一个从相遇点，一个从头，同时走，相遇即环入口
                ListNode *p = head;
                while (p != slow) {
                    p = p->next;
                    slow = slow->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution sol;

    // 3->2->0->-4, 环入口为 2
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2;
    ListNode* result = sol.detectCycle(n1);
    cout << (result ? result->val : -1) << endl; // 2

    // 1->2, 环入口为 1
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    a->next = b; b->next = a;
    result = sol.detectCycle(a);
    cout << (result ? result->val : -1) << endl; // 1

    // 无环: 1->2->3
    ListNode* h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(3);
    result = sol.detectCycle(h);
    cout << (result ? result->val : -1) << endl; // -1

    return 0;
}
