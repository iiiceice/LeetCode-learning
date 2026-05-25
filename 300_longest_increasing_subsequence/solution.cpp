/**
 * 300. Longest Increasing Subsequence
 * Medium
 * 动态规划 + 二分查找（贪心）
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] 表示长度为 i+1 的递增子序列的最小末尾元素
        // 末尾越小，越容易接上更大的数，所以贪心地维护最小末尾
        vector<int> dp;
        for (int num : nums) {
            auto it = lower_bound(dp.begin(), dp.end(), num);
            if (it == dp.end()) {
                dp.push_back(num); // 比所有末尾都大，可以延长
            } else {
                *it = num; // 替换，让末尾更小
            }
        }
        return dp.size();
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << sol.lengthOfLIS(nums1) << endl; // 4

    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << sol.lengthOfLIS(nums2) << endl; // 4

    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << sol.lengthOfLIS(nums3) << endl; // 1

    return 0;
}
