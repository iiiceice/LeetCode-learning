// 31. 下一个排列 (Next Permutation)
// 难度：中等
// 标签：数组、双指针

/*
思路：从后向前扫描，分三步（要求原地修改、O(1) 额外空间）
1. 找"升降点"：从后往前找第一个 nums[i] < nums[i+1] 的位置 i。
   i 之后的部分是降序（已经是该后缀的最大排列）。
   如果找不到，说明整个数组是降序（已是最大排列），直接整体反转成最小排列。
2. 找交换对象：从后往前找第一个大于 nums[i] 的数 nums[j]，
   交换 nums[i] 和 nums[j]。交换后 i 之后仍保持降序。
3. 反转后缀：把 i 之后的降序区间反转成升序，得到"刚好大一点点"的排列。

例子：1 5 8 4 7 6 5 3 1
- 从后往前，4 < 7，i 指向 4
- 从后往前找第一个 > 4 的数是 5，交换 → 1 5 8 5 7 6 4 3 1
- 反转后缀 → 1 5 8 5 1 3 4 6 7

时间 O(n)，空间 O(1)。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        // 1. 从后往前找第一个 nums[i] < nums[i+1]
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        if (i >= 0) {  // 存在升降点才需要交换；i<0 说明整体降序，跳过交换
            // 2. 从后往前找第一个大于 nums[i] 的数
            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        // 3. 反转 i 之后的后缀（i<0 时就是反转整个数组）
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    Solution sol;
    // 测试用例 1：期望 1 3 2
    vector<int> a = {1, 2, 3};
    sol.nextPermutation(a);
    cout << "1,2,3 -> ";
    for (int x : a) cout << x << " ";
    cout << "(期望 1 3 2)" << endl;
    // 测试用例 2：期望 1 2 3（最大排列回绕到最小）
    vector<int> b = {3, 2, 1};
    sol.nextPermutation(b);
    cout << "3,2,1 -> ";
    for (int x : b) cout << x << " ";
    cout << "(期望 1 2 3)" << endl;
    // 测试用例 3：期望 1 5 1
    vector<int> c = {1, 1, 5};
    sol.nextPermutation(c);
    cout << "1,1,5 -> ";
    for (int x : c) cout << x << " ";
    cout << "(期望 1 5 1)" << endl;
    // 测试用例 4：含重复元素
    // 手推：i 指向 1(下标1)，j 指向 3，交换得 2,3,1,1，后缀有序无需变
    vector<int> d = {2, 1, 3, 1};
    sol.nextPermutation(d);
    cout << "2,1,3,1 -> ";
    for (int x : d) cout << x << " ";
    cout << "(期望 2 3 1 1)" << endl;
    return 0;
}
