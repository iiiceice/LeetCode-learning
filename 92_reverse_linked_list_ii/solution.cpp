/**
 * 92. Reverse Linked List II
 * Medium
 * 反转区间 [m, n] 的链表（一次遍历，dummy + 头插法）
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        // dummy 解决 m=1 时 head 没有前驱的边界
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        // 1. pre 走到第 m-1 个节点（反转段的前驱）
        ListNode *pre = dummy;
        for (int i = 1; i < m; i++) pre = pre->next;

        // 2. cur 固定在原始第 m 个节点，反转后它就是段尾
        ListNode *cur = pre->next;

        // 3. 循环 n-m 次：每次把 cur->next 摘下来插到 pre 后面（段首）
        for (int i = m; i < n; i++) {
            ListNode *nxt = cur->next;  // 要前插的节点
            cur->next = nxt->next;      // cur 跳过 nxt（cur 最终接后半段）
            nxt->next = pre->next;      // nxt 指向原段首
            pre->next = nxt;            // nxt 成为新段首
        }
        return dummy->next;
    }
};

// 构建链表：1->2->3->4->5
ListNode* buildList() {
    ListNode* head = new ListNode(1);
    ListNode* cur = head;
    for (int v = 2; v <= 5; v++) {
        cur->next = new ListNode(v);
        cur = cur->next;
    }
    return head;
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // 测试用例 1: m=2, n=4 -> 1 4 3 2 5
    printList(sol.reverseBetween(buildList(), 2, 4));

    // 测试用例 2: m=1, n=5（从头部反转，考验 dummy）-> 5 4 3 2 1
    printList(sol.reverseBetween(buildList(), 1, 5));

    // 测试用例 3: m=n（不反转）-> 1 2 3 4 5
    printList(sol.reverseBetween(buildList(), 3, 3));

    // 测试用例 4: m=1, n=2 -> 2 1 3 4 5
    printList(sol.reverseBetween(buildList(), 1, 2));

    return 0;
}
