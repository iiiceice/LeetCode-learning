/**
 * 104. 二叉树的最大深度 (Maximum Depth of Binary Tree)
 * 难度：Easy
 * 标签：二叉树、递归、DFS、BFS
 *
 * 思路：递归（DFS）：一棵树的深度 = 1 + max(左子树深度, 右子树深度)。
 *       也给出 BFS 层序遍历写法，统计层数即为深度。
 */

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 递归 DFS
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }

    // BFS 层序遍历
    int maxDepth_bfs(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                TreeNode* node = q.front(); q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            depth++;
        }

        return depth;
    }
};

int main() {
    Solution sol;

    // 3 -> (9, 20 -> (15, 7))
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << sol.maxDepth(root) << endl;     // 3
    cout << sol.maxDepth_bfs(root) << endl; // 3

    cout << sol.maxDepth(nullptr) << endl;  // 0

    TreeNode* single = new TreeNode(1);
    cout << sol.maxDepth(single) << endl;   // 1

    return 0;
}
