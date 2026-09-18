/**
 * 102. 二叉树的层序遍历 (Binary Tree Level Order Traversal)
 * 难度：Medium
 * 标签：二叉树、BFS、队列
 *
 * 思路：用队列做 BFS，外层循环每次处理"当前一整层"。
 *       关键技巧：进入下一层前记录 q.size()，这个数字就是本层节点数，
 *       据此精确切分每一层，把同一层的值收集到同一个 vector。
 *       复杂度 O(n)，每个节点入队出队各一次。
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();          // 本层节点数，固定下来防止循环内变动
            vector<int> level;
            level.reserve(sz);

            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                level.push_back(node->val);
                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(move(level));
        }
        return res;
    }
};

// 辅助：打印二维 vector
void print(const vector<vector<int>>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << (j + 1 < v[i].size() ? "," : "");
        }
        cout << "]" << (i + 1 < v.size() ? "," : "");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;

    // 测试 1：3 -> (9, 20 -> (15, 7))
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    print(sol.levelOrder(root1));   // [[3],[9,20],[15,7]]

    // 测试 2：单节点
    TreeNode* single = new TreeNode(1);
    print(sol.levelOrder(single));  // [[1]]

    // 测试 3：空树
    print(sol.levelOrder(nullptr)); // []

    // 测试 4：左斜树 1 -> 2 -> 3
    TreeNode* leftChain = new TreeNode(1);
    leftChain->left = new TreeNode(2);
    leftChain->left->left = new TreeNode(3);
    print(sol.levelOrder(leftChain)); // [[1],[2],[3]]

    return 0;
}
