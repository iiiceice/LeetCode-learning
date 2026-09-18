/**
 * 25. Reverse Nodes in k-Group
 * Hard
 * K 个一组翻转链表（链表 + 模拟）
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode *prevGroupEnd = &dummy; // 上一组翻转后的尾节点

        while (true) {
            // 1. 从 prevGroupEnd 往后数 k 个节点，看是否够一组
            ListNode *groupTail = prevGroupEnd;
            for (int i = 0; i < k; ++i) {
                groupTail = groupTail->next;
                if (!groupTail) return dummy.next; // 不足 k 个，直接结束
            }

            // 2. 记录下一组起点，断开当前组
            ListNode *nextGroupHead = groupTail->next;
            ListNode *groupHead = prevGroupEnd->next;

            // 3. 翻转 [groupHead, groupTail] 这一段（用 head 插入法）
            ListNode *prev = nextGroupHead; // 翻转后 groupHead 指向下一组
            ListNode *curr = groupHead;
            while (curr != nextGroupHead) {
                ListNode *nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            // 4. 接回主链：原 prevGroupEnd -> 翻转后的新头 groupTail
            prevGroupEnd->next = groupTail;
            // 更新 prevGroupEnd 为这一组翻转后的尾节点（即原 groupHead）
            prevGroupEnd = groupHead;
        }
        return dummy.next;
    }
};

// 辅助：根据数组构建链表
ListNode* buildList(initializer_list<int> vals) {
    ListNode dummy(0);
    ListNode *tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

// 辅助：打印链表
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // 测试 1: 1->2->3->4->5, k=2 => 2->1->4->3->5
    ListNode* h = buildList({1, 2, 3, 4, 5});
    printList(sol.reverseKGroup(h, 2));

    // 测试 2: 1->2->3->4->5, k=3 => 3->2->1->4->5
    h = buildList({1, 2, 3, 4, 5});
    printList(sol.reverseKGroup(h, 3));

    // 测试 3: k=1, 不变
    h = buildList({1, 2, 3});
    printList(sol.reverseKGroup(h, 1));

    // 测试 4: 空链表
    printList(sol.reverseKGroup(nullptr, 2));

    // 测试 5: 长度刚好整除
    h = buildList({1, 2, 3, 4});
    printList(sol.reverseKGroup(h, 2)); // 2 1 4 3

    return 0;
}
