/**
 * 141. Linked List Cycle
 * Easy
 * 快慢指针
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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main() {
    Solution sol;

    // 有环: 3->2->0->-4, -4 指回 2
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2;
    cout << sol.hasCycle(n1) << endl; // 1

    // 无环: 1->2->3
    ListNode* h2 = new ListNode(1);
    h2->next = new ListNode(2);
    h2->next->next = new ListNode(3);
    cout << sol.hasCycle(h2) << endl; // 0

    // 空链表
    cout << sol.hasCycle(nullptr) << endl; // 0

    return 0;
}
