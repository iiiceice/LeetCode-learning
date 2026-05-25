/**
 * 46. Permutations
 * Medium
 * 回溯
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, path, result);
        return result;
    }

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used, path, result);
            path.pop_back();
            used[i] = false;
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 3};
    auto res = sol.permute(nums1);
    for (auto& p : res) {
        for (int x : p) cout << x << " ";
        cout << endl;
    }
    // 123 132 213 231 312 321

    vector<int> nums2 = {0, 1};
    res = sol.permute(nums2);
    for (auto& p : res) {
        for (int x : p) cout << x << " ";
        cout << endl;
    }
    // 01 10

    return 0;
}
