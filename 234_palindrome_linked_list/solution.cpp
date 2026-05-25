/**
 * 234. Palindrome Linked List
 * Easy
 * 快慢指针找中点 + 反转后半部分
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
    bool isPalindrome(ListNode* head) {
        // 快慢指针找中点
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 反转后半部分
        ListNode *prev = nullptr, *curr = slow;
        while (curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // 前半 和 反转后的后半 逐个比较
        ListNode *left = head, *right = prev;
        while (right) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }
        return true;
    }
};

int main() {
    Solution sol;

    // 1->2->2->1
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(2);
    h1->next->next->next = new ListNode(1);
    cout << sol.isPalindrome(h1) << endl; // 1

    // 1->2
    ListNode* h2 = new ListNode(1);
    h2->next = new ListNode(2);
    cout << sol.isPalindrome(h2) << endl; // 0

    // 1->2->3->2->1
    ListNode* h3 = new ListNode(1);
    h3->next = new ListNode(2);
    h3->next->next = new ListNode(3);
    h3->next->next->next = new ListNode(2);
    h3->next->next->next->next = new ListNode(1);
    cout << sol.isPalindrome(h3) << endl; // 1

    return 0;
}
