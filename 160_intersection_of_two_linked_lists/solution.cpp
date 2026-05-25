/**
 * 160. Intersection of Two Linked Lists
 * Easy
 * 双指针
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 双指针，各自走完自己的链表后走对方的链表
        // 如果有交点，两指针一定在交点相遇；没有交点，同时走到 nullptr
        ListNode *a = headA, *b = headB;
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};

int main() {
    Solution sol;

    // 构造交点链表: A: 4->1->8->4->5, B: 5->6->1->8->4->5
    //                        ^c1              ^c1
    ListNode* c1 = new ListNode(8);
    c1->next = new ListNode(4);
    c1->next->next = new ListNode(5);

    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = c1;

    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = c1;

    ListNode* result = sol.getIntersectionNode(headA, headB);
    cout << (result ? result->val : -1) << endl; // 8

    // 测试用例 2: 无交点
    ListNode* hA = new ListNode(2);
    hA->next = new ListNode(6);
    hA->next->next = new ListNode(4);

    ListNode* hB = new ListNode(1);
    hB->next = new ListNode(5);

    result = sol.getIntersectionNode(hA, hB);
    cout << (result ? result->val : -1) << endl; // -1

    return 0;
}
