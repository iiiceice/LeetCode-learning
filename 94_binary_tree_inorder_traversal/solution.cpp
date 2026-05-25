/**
 * 94. 二叉树的中序遍历 (Binary Tree Inorder Traversal)
 * 难度：Easy
 * 标签：二叉树、递归、栈
 *
 * 思路：中序遍历顺序：左子树 → 根 → 右子树。
 *       递归写法最直观；也给出迭代写法用栈模拟递归调用栈。
 */

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 递归
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode* node, vector<int>& ans) {
        if (!node) return;
        dfs(node->left, ans);
        ans.push_back(node->val);
        dfs(node->right, ans);
    }

    // 迭代写法
    vector<int> inorderTraversal_iter(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* cur = root;

        while (cur || !stk.empty()) {
            while (cur) {           // 一路向左走，压栈
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();        // 弹出访问
            stk.pop();
            ans.push_back(cur->val);
            cur = cur->right;       // 转向右子树
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // 构造树: 1 -> null, right=2, 2.left=3
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    auto r1 = sol.inorderTraversal(root);
    for (int v : r1) cout << v << " "; // 1 3 2
    cout << endl;

    auto r2 = sol.inorderTraversal_iter(root);
    for (int v : r2) cout << v << " "; // 1 3 2
    cout << endl;

    // 空树
    cout << sol.inorderTraversal(nullptr).size() << endl; // 0

    return 0;
}
