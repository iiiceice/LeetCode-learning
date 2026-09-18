/**
 * 543. 二叉树的直径 (Diameter of Binary Tree)
 * 难度：Easy
 * 标签：二叉树、递归、DFS、后序遍历
 *
 * 思路：直径 = 任意两节点之间路径上的边数最大值。
 *       对每个节点 node，经过它的最长路径 = 左子树高度 + 右子树高度。
 *       后序遍历时维护全局最大值 ans，递归返回 max(左高, 右高) + 1 给父节点用。
 *       注意：直径不一定经过根，所以必须每个节点都算一次。
 */

#include <iostream>
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
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        height(root, ans);
        return ans;
    }

private:
    // 返回以 node 为根的树的高度（叶子节点高度为 1），同时更新直径 ans
    int height(TreeNode* node, int& ans) {
        if (!node) return 0;
        int l = height(node->left, ans);
        int r = height(node->right, ans);
        ans = max(ans, l + r);          // 经过 node 的路径边数 = l + r
        return max(l, r) + 1;
    }
};

int main() {
    Solution sol;

    // 测试 1：1 -> (2 -> (4, 5), 3)，直径 = 3 (4->2->1->3 或 5->2->1->3)
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);
    cout << sol.diameterOfBinaryTree(root1) << endl;  // 3

    // 测试 2：1 -> (2,)，直径 = 1
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    cout << sol.diameterOfBinaryTree(root2) << endl;  // 1

    // 测试 3：空树，直径 = 0
    cout << sol.diameterOfBinaryTree(nullptr) << endl; // 0

    // 测试 4：单节点，直径 = 0
    TreeNode* single = new TreeNode(1);
    cout << sol.diameterOfBinaryTree(single) << endl;  // 0

    // 测试 5：左斜树 4 -> 3 -> 2 -> 1，直径 = 3
    TreeNode* leftChain = new TreeNode(4);
    leftChain->left = new TreeNode(3);
    leftChain->left->left = new TreeNode(2);
    leftChain->left->left->left = new TreeNode(1);
    cout << sol.diameterOfBinaryTree(leftChain) << endl; // 3

    return 0;
}
