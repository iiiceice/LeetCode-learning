/**
 * 560. Subarray Sum Equals K
 * Medium
 * 前缀和 + 哈希表
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 前缀和 -> 该前缀和出现的次数
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // 前缀和为0出现1次，处理从开头开始的子数组

        int sum = 0, count = 0;
        for (int num : nums) {
            sum += num;
            // 如果存在前缀和 sum - k，说明中间这段子数组和为 k
            if (prefixCount.count(sum - k)) {
                count += prefixCount[sum - k];
            }
            prefixCount[sum]++;
        }
        return count;
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {1, 1, 1};
    cout << sol.subarraySum(nums1, 2) << endl; // 2

    // 测试用例 2
    vector<int> nums2 = {1, 2, 3};
    cout << sol.subarraySum(nums2, 3) << endl; // 2

    // 测试用例 3: 含负数
    vector<int> nums3 = {1, -1, 0};
    cout << sol.subarraySum(nums3, 0) << endl; // 3

    return 0;
}
