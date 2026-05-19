/**
 * 1. 两数之和 (Two Sum)
 * 简单
 * 标签: 哈希表
 *
 * 思路: 用哈希表记录 <值, 下标>，遍历数组时查找 target - nums[i] 是否已在表中
 * 时间 O(n)，空间 O(n)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // 值 -> 下标
        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            if (mp.count(complement)) {
                return {mp[complement], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> nums1 = {2, 7, 11, 15};
    auto res1 = sol.twoSum(nums1, 9);
    cout << "测试1: [" << res1[0] << ", " << res1[1] << "]" << endl;
    // 期望: [0, 1]

    // 测试用例 2
    vector<int> nums2 = {3, 2, 4};
    auto res2 = sol.twoSum(nums2, 6);
    cout << "测试2: [" << res2[0] << ", " << res2[1] << "]" << endl;
    // 期望: [1, 2]

    // 测试用例 3
    vector<int> nums3 = {3, 3};
    auto res3 = sol.twoSum(nums3, 6);
    cout << "测试3: [" << res3[0] << ", " << res3[1] << "]" << endl;
    // 期望: [0, 1]

    return 0;
}
