/**
 * 55. 跳跃游戏
 * 难度：中等
 * 标签：贪心、数组、动态规划
 *
 * 思路：贪心，维护从起点出发能到达的最远下标 farthest。
 *       遍历每个位置 i，若 i > farthest 说明不可达，返回 false。
 *       否则更新 farthest = max(farthest, i + nums[i])。
 *       最后检查 farthest 是否 >= 最后一个下标。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > farthest) return false;
            farthest = max(farthest, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution sol;

    // 测试用例 1：可以到达
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1: " << (sol.canJump(nums1) ? "true" : "false") << " (expected true)" << endl;

    // 测试用例 2：无法到达
    vector<int> nums2 = {3, 2, 1, 0, 4};
    cout << "Test 2: " << (sol.canJump(nums2) ? "true" : "false") << " (expected false)" << endl;

    // 测试用例 3：单个元素
    vector<int> nums3 = {0};
    cout << "Test 3: " << (sol.canJump(nums3) ? "true" : "false") << " (expected true)" << endl;

    return 0;
}
