/**
 * 198. 打家劫舍 (House Robber)
 * 中等
 * 标签: 动态规划
 *
 * 思路: 对于第 i 个房子，有两种选择：
 *       偷：dp[i] = dp[i-2] + nums[i]（不能偷相邻的，所以取前前个的最优）
 *       不偷：dp[i] = dp[i-1]
 *       取两者最大值
 * 时间 O(n)，空间 O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int prev2 = nums[0];                 // dp[0]
        int prev1 = max(nums[0], nums[1]);   // dp[1]
        for (int i = 2; i < n; i++) {
            int cur = max(prev1, prev2 + nums[i]); // 偷或不偷
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 1};
    cout << sol.rob(nums1) << endl;  // 4 (偷0号和2号: 1+3)

    vector<int> nums2 = {2, 7, 9, 3, 1};
    cout << sol.rob(nums2) << endl;  // 12 (偷0号、2号、4号: 2+9+1)

    vector<int> nums3 = {2, 1, 1, 2};
    cout << sol.rob(nums3) << endl;  // 4 (偷0号和3号: 2+2)

    return 0;
}
