/**
 * 53. 最大子数组和 (Maximum Subarray)
 * 难度：Medium
 * 标签：动态规划、Kadane算法
 *
 * 思路：遍历数组，维护以当前元素结尾的最大子数组和 dp[i]。
 *       dp[i] = max(nums[i], dp[i-1] + nums[i])
 *       即：要么把前面的接上，要么从当前元素重新开始。
 *       遍历过程中取 dp 的最大值即为答案。
 *       空间优化：只需一个变量记录前一个 dp 值。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cur = nums[0]; // 以当前元素结尾的最大子数组和
        int ans = nums[0];

        for (int i = 1; i < (int)nums.size(); i++) {
            cur = max(nums[i], cur + nums[i]);
            ans = max(ans, cur);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> n1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sol.maxSubArray(n1) << endl; // 6 ([4,-1,2,1])

    vector<int> n2 = {1};
    cout << sol.maxSubArray(n2) << endl; // 1

    vector<int> n3 = {5, 4, -1, 7, 8};
    cout << sol.maxSubArray(n3) << endl; // 23 (整个数组)

    vector<int> n4 = {-1};
    cout << sol.maxSubArray(n4) << endl; // -1

    return 0;
}
