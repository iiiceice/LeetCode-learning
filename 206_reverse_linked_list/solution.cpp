/**
 * 206. Reverse Linked List
 * Easy
 * 链表反转（迭代 + 递归）
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
    // 迭代：逐个把节点指向前面
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *next = curr->next; // 保存下一个
            curr->next = prev;           // 反转指向
            prev = curr;                 // prev 前进
            curr = next;                 // curr 前进
        }
        return prev;
    }
};

int main() {
    Solution sol;

    // 1->2->3->4->5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = sol.reverseList(head);
    while (result) {
        cout << result->val << " "; // 5 4 3 2 1
        result = result->next;
    }
    cout << endl;

    // 测试用例 2: 空链表
    result = sol.reverseList(nullptr);
    cout << (result ? "not null" : "null") << endl; // null

    // 测试用例 3: 单节点
    ListNode* single = new ListNode(1);
    result = sol.reverseList(single);
    cout << result->val << endl; // 1

    return 0;
}
