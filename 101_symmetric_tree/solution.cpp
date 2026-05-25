/**
 * 101. 对称二叉树 (Symmetric Tree)
 * 难度：Easy
 * 标签：二叉树、递归
 *
 * 思路：一棵树对称，当且仅当左子树和右子树互为镜像。
 *       即：左的左 == 右的右，左的右 == 右的左，且根值相等。
 *       同时递归比较 (left->left, right->right) 和 (left->right, right->left)。
 */

#include <iostream>
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
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }

    bool check(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;  // 都为空，对称
        if (!left || !right) return false; // 一个空一个不空，不对称
        if (left->val != right->val) return false;
        return check(left->left, right->right) && check(left->right, right->left);
    }
};

int main() {
    Solution sol;

    // 1(2(3,4), 2(4,3))
    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(2);
    t1->left->left = new TreeNode(3);
    t1->left->right = new TreeNode(4);
    t1->right->left = new TreeNode(4);
    t1->right->right = new TreeNode(3);
    cout << sol.isSymmetric(t1) << endl; // 1

    // 1(2(_,3), 2(_,3))
    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->right = new TreeNode(2);
    t2->left->right = new TreeNode(3);
    t2->right->right = new TreeNode(3);
    cout << sol.isSymmetric(t2) << endl; // 0

    // 单节点
    TreeNode* t3 = new TreeNode(1);
    cout << sol.isSymmetric(t3) << endl; // 1

    return 0;
}
