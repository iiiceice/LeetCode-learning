/**
 * 138. Copy List with Random Pointer
 * Medium
 * 复制带随机指针的链表（哈希表 / 原地拼接）
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Node 比 ListNode 多一个 random 指针
class Node {
public:
    int val;
    Node *next;
    Node *random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
};

class Solution {
public:
    // 写法一：哈希表，两次遍历
    // 第一次：建立 原节点 -> 新节点 的映射
    // 第二次：按原链表的 next / random 关系，连接新节点
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        unordered_map<Node*, Node*> mp;

        for (Node* p = head; p; p = p->next) {
            mp[p] = new Node(p->val);
        }
        for (Node* p = head; p; p = p->next) {
            mp[p]->next = mp[p->next];     // mp[nullptr] 会插入 {nullptr, nullptr}？不会，需要特判
            mp[p]->random = mp[p->random]; // 同上
        }
        // 注：unordered_map 对不存在的 key 会插入默认值（nullptr），所以这里看似访问 mp[nullptr]
        //     实际会插入 {nullptr, nullptr}，结果仍为 nullptr，逻辑正确。但若想严谨，可改为 .count() 判断。
        return mp[head];
    }
};

// 写法二：原地拼接，O(1) 空间
// 思路：
//   1. 在每个原节点后面插入它的复制：A -> A' -> B -> B' -> ...
//   2. 设置 random：copy->random = orig->random->next
//   3. 拆分两个链表
// class Solution {
// public:
//     Node* copyRandomList(Node* head) {
//         if (!head) return nullptr;
//
//         // 1. 插入复制节点
//         for (Node* p = head; p; p = p->next->next) {
//             Node* copy = new Node(p->val);
//             copy->next = p->next;
//             p->next = copy;
//         }
//
//         // 2. 设置 random
//         for (Node* p = head; p; p = p->next->next) {
//             if (p->random) p->next->random = p->random->next;
//         }
//
//         // 3. 拆分（同时恢复原链表的 next）
//         Node* newHead = head->next;
//         for (Node* p = head; p; p = p->next) {
//             Node* copy = p->next;
//             p->next = copy->next;          // 恢复原链表
//             copy->next = copy->next ? copy->next->next : nullptr; // 连接新链表
//         }
//         return newHead;
//     }
// };

// ---------- 测试 ----------

// 辅助：根据 val 数组和 random 索引数组构建链表
// randomIdx[i] = -1 表示 nullptr，否则表示指向第 i 个节点
Node* buildList(initializer_list<int> vals, initializer_list<int> randomIdx) {
    if (vals.size() == 0) return nullptr;
    vector<Node*> nodes;
    vector<int> ridx(randomIdx);
    int i = 0;
    for (int v : vals) {
        nodes.push_back(new Node(v));
        if (i > 0) nodes[i - 1]->next = nodes[i];
        ++i;
    }
    for (int i = 0; i < (int)nodes.size(); ++i) {
        if (ridx[i] != -1) nodes[i]->random = nodes[ridx[i]];
    }
    return nodes[0];
}

// 辅助：打印链表：val -> (random.val | null)
void printList(Node* head) {
    while (head) {
        cout << "[" << head->val << ",";
        if (head->random) cout << head->random->val;
        else cout << "null";
        cout << "] ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    // 测试 1: 经典用例
    // 7 -> 13 -> 11 -> 10 -> 1
    // random: 7->null, 13->7, 11->1, 10->11, 1->null
    Node* h = buildList({7, 13, 11, 10, 1}, {-1, 0, 4, 2, -1});
    Node* copied = sol.copyRandomList(h);
    printList(copied);
    // 期望：[7,null] [13,7] [11,1] [10,11] [1,null]

    // 测试 2: 空链表
    cout << (sol.copyRandomList(nullptr) ? "not null" : "null") << endl; // null

    // 测试 3: 单节点，random 指向自己
    Node* single = new Node(1);
    single->random = single;
    printList(sol.copyRandomList(single)); // [1,1]

    // 测试 4: 两个节点互相 random
    h = buildList({1, 2}, {1, 0});
    printList(sol.copyRandomList(h)); // [1,2] [2,1]

    return 0;
}
