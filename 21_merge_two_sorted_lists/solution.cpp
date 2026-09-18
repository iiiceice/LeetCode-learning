/**
 * 21. Merge Two Sorted Lists
 * Easy
 * 合并两个有序链表（迭代 + 递归）
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
    // 迭代：哑节点 + 双指针比较
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);          // 哑节点，简化头节点处理
        ListNode *tail = &dummy;    // 始终指向结果链表的末尾

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        // 把剩余部分直接接上
        tail->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

// 递归写法（思路：选较小的节点作为头，它的 next 指向剩余两链表的合并结果）
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         if (!list1) return list2;
//         if (!list2) return list1;
//         if (list1->val <= list2->val) {
//             list1->next = mergeTwoLists(list1->next, list2);
//             return list1;
//         } else {
//             list2->next = mergeTwoLists(list1, list2->next);
//             return list2;
//         }
//     }
// };

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

    // 测试用例 1: 1->2->4 与 1->3->4 合并
    ListNode* l1 = buildList({1, 2, 4});
    ListNode* l2 = buildList({1, 3, 4});
    printList(sol.mergeTwoLists(l1, l2)); // 1 1 2 3 4 4

    // 测试用例 2: 两个空链表
    printList(sol.mergeTwoLists(nullptr, nullptr)); // (空)

    // 测试用例 3: 一个空一个非空
    l1 = nullptr;
    l2 = buildList({0});
    printList(sol.mergeTwoLists(l1, l2)); // 0

    return 0;
}
