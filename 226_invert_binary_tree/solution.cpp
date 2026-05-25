/**
 * 226. 翻转二叉树 (Invert Binary Tree)
 * 难度：Easy
 * 标签：二叉树、递归
 *
 * 思路：递归交换每个节点的左右子树即可。
 *       先翻左子树，再翻右子树，最后交换左右指针。
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};

// 层序打印验证
void printLevel(TreeNode* root) {
    if (!root) { cout << "empty" << endl; return; }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        cout << node->val << " ";
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    cout << endl;
}

int main() {
    Solution sol;

    // 4 -> (2->(1,3), 7->(6,9))
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    printLevel(root);             // 4 2 7 1 3 6 9
    root = sol.invertTree(root);
    printLevel(root);             // 4 7 2 9 6 3 1

    cout << (sol.invertTree(nullptr) == nullptr) << endl; // 1

    return 0;
}
