/**
 * 手撕快排
 * 标签：排序、分治
 *
 * 思路：选一个基准元素（这里取中间），将数组分为 <pivot 和 >pivot 两部分，
 *       递归对左右两部分排序。时间 O(n log n) 平均，最坏 O(n^2)。
 *       这里用三路划分（< pivot / == pivot / > pivot），天然处理重复元素。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, (int)nums.size() - 1);
        return nums;
    }

private:
    void quickSort(vector<int>& nums, int lo, int hi) {
        if (lo >= hi) return;
        // 三路划分：[lo, lt) < pivot, [lt, gt] == pivot, (gt, hi] > pivot
        int pivot = nums[lo + (hi - lo) / 2];
        int lt = lo, i = lo, gt = hi;
        while (i <= gt) {
            if (nums[i] < pivot) {
                swap(nums[lt++], nums[i++]);
            } else if (nums[i] > pivot) {
                swap(nums[i], nums[gt--]);
            } else {
                i++;
            }
        }
        // 现在 [lo, lt-1] < pivot, [lt, gt] == pivot, [gt+1, hi] > pivot
        quickSort(nums, lo, lt - 1);
        quickSort(nums, gt + 1, hi);
    }
};

int main() {
    Solution sol;

    // 测试用例 1：普通乱序
    vector<int> nums1 = {5, 2, 3, 1};
    sol.sortArray(nums1);
    cout << "Test 1: ";
    for (int x : nums1) cout << x << " ";
    cout << "(expected 1 2 3 5)" << endl;

    // 测试用例 2：大量重复元素
    vector<int> nums2 = {5, 1, 1, 2, 0, 0};
    sol.sortArray(nums2);
    cout << "Test 2: ";
    for (int x : nums2) cout << x << " ";
    cout << "(expected 0 0 1 1 2 5)" << endl;

    // 测试用例 3：已排序
    vector<int> nums3 = {1, 2, 3, 4, 5};
    sol.sortArray(nums3);
    cout << "Test 3: ";
    for (int x : nums3) cout << x << " ";
    cout << "(expected 1 2 3 4 5)" << endl;

    return 0;
}
