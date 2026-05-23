/**
 * 45. 跳跃游戏 II
 * 难度：中等
 * 标签：贪心、数组
 *
 * 思路：BFS 思路的贪心。把跳跃过程看成按层扩展：
 *       当前步数能覆盖的范围 [lo, hi]，在这个范围内找出下一步能到达的最远位置 nextFarthest。
 *       遍历完当前范围后，步数 +1，新区间变为 [hi+1, nextFarthest]。
 *       当 farthest >= n-1 时说明已能到达终点。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int steps = 0;
        int farthest = 0;    // 当前步数能到达的最远位置
        int boundary = 0;    // 当前步数的右边界

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);
            if (i == boundary) {
                steps++;
                boundary = farthest;
            }
        }
        return steps;
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    cout << "Test 1: " << sol.jump(nums1) << " (expected 2)" << endl;

    // 测试用例 2：已经不需要跳
    vector<int> nums2 = {0};
    cout << "Test 2: " << sol.jump(nums2) << " (expected 0)" << endl;

    // 测试用例 3
    vector<int> nums3 = {1, 2, 1, 1, 1};
    cout << "Test 3: " << sol.jump(nums3) << " (expected 3)" << endl;

    return 0;
}
