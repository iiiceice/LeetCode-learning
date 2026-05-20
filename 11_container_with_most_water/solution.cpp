/**
 * 11. 盛最多水的容器 (Container With Most Water)
 * 中等
 * 标签: 双指针
 *
 * 思路: 左右双指针向内收缩，面积 = min(h[l], h[r]) * (r - l)
 *       每次移动较矮的指针：因为面积受限于短边，
 *       移动长边只会让宽度变小、高度不可能增加，面积一定变小
 *       移动短边才可能遇到更高的柱子，获得更大面积
 * 时间 O(n)，空间 O(1)
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> h1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << sol.maxArea(h1) << endl;  // 49

    vector<int> h2 = {1, 1};
    cout << sol.maxArea(h2) << endl;  // 1

    vector<int> h3 = {4, 3, 2, 1, 4};
    cout << sol.maxArea(h3) << endl;  // 16

    return 0;
}
