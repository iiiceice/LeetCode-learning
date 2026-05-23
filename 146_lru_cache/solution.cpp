/**
 * 146. LRU 缓存 (LRU Cache)
 * 中等
 * 标签: 设计, 哈希表, 链表
 *
 * 思路: 哈希表 + 双向链表
 *       哈希表 O(1) 查找 key 对应的链表节点
 *       双向链表维护访问顺序，最近访问的放头部，尾部是最久未访问的
 *       get: 查哈希表，命中则把节点移到链表头部
 *       put: key 已存在则更新值并移到头部；
 *            key 不存在则创建新节点插到头部，超容量时删除尾部节点
 * get/put 均 O(1)，空间 O(capacity)
 */

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int key, val;
    Node *prev, *next;
    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> mp;
    Node *head, *tail; // 哑节点，head->next 是最近访问，tail->prev 是最久未访问

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void moveToHead(Node* node) {
        remove(node);
        addToFront(node);
    }

    Node* removeTail() {
        Node* lru = tail->prev;
        remove(lru);
        return lru;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        moveToHead(mp[key]);
        return mp[key]->val;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key]->val = value;
            moveToHead(mp[key]);
            return;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        addToFront(node);
        if ((int)mp.size() > cap) {
            Node* lru = removeTail();
            mp.erase(lru->key);
            delete lru;
        }
    }
};

int main() {
    LRUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl;   // 1，现在 1 是最近访问，2 是最久

    cache.put(3, 3);                // 淘汰 key=2
    cout << cache.get(2) << endl;   // -1，已被淘汰

    cache.put(4, 4);                // 淘汰 key=1
    cout << cache.get(1) << endl;   // -1
    cout << cache.get(3) << endl;   // 3
    cout << cache.get(4) << endl;   // 4

    return 0;
}
