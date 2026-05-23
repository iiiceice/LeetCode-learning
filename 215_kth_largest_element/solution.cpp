/**
 * 215. 数组中的第K个最大元素 (Kth Largest Element in an Array)
 * 中等
 * 标签: 堆, 优先队列
 *
 * 思路: 最小堆，维护大小为 k 的堆
 *       遍历数组，元素入堆，堆大小超过 k 时弹出堆顶（最小的）
 *       遍历完后堆顶就是第 k 大的元素
 * 时间 O(nlogk)，空间 O(k)
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if ((int)minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    cout << sol.findKthLargest(nums1, 2) << endl;  // 5

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << sol.findKthLargest(nums2, 4) << endl;  // 4

    vector<int> nums3 = {1};
    cout << sol.findKthLargest(nums3, 1) << endl;  // 1

    return 0;
}
