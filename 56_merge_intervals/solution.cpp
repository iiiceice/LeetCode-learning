/**
 * 56. 合并区间 (Merge Intervals)
 * 难度：Medium
 * 标签：排序、贪心
 *
 * 思路：先按区间左端点排序，再逐个合并。
 *       维护当前区间 [cur_l, cur_r]，遍历每个区间：
 *       - 若与当前区间重叠（左端点 <= cur_r），更新 cur_r 为较大的右端点
 *       - 否则把当前区间存入结果，开启新区间
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end()); // 按左端点排序
        vector<vector<int>> ans;
        int cur_l = intervals[0][0], cur_r = intervals[0][1];

        for (int i = 1; i < (int)intervals.size(); i++) {
            if (intervals[i][0] <= cur_r) {
                cur_r = max(cur_r, intervals[i][1]); // 重叠，扩展右端点
            } else {
                ans.push_back({cur_l, cur_r}); // 不重叠，保存当前区间
                cur_l = intervals[i][0];
                cur_r = intervals[i][1];
            }
        }
        ans.push_back({cur_l, cur_r}); // 别忘了最后一个

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> v1 = {{1,3},{2,6},{8,10},{15,18}};
    auto r1 = sol.merge(v1);
    for (auto& v : r1) cout << "[" << v[0] << "," << v[1] << "] "; // [1,6] [8,10] [15,18]
    cout << endl;

    vector<vector<int>> v2 = {{1,4},{4,5}};
    auto r2 = sol.merge(v2);
    for (auto& v : r2) cout << "[" << v[0] << "," << v[1] << "] "; // [1,5]
    cout << endl;

    vector<vector<int>> v3 = {{1,4},{0,4}};
    auto r3 = sol.merge(v3);
    for (auto& v : r3) cout << "[" << v[0] << "," << v[1] << "] "; // [0,4]
    cout << endl;

    return 0;
}
