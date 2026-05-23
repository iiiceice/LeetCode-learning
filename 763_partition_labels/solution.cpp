/**
 * 763. 划分字母区间
 * 难度：中等
 * 标签：贪心、字符串、哈希表
 *
 * 思路：第一遍扫描记录每个字母最后出现的位置 last[c]。
 *       第二遍扫描，维护当前片段的右边界 end = max(end, last[c])。
 *       当 i == end 时，说明当前片段内所有字母都不会再出现，可以切分。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int last[26] = {};
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }

        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                res.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<int> res1 = sol.partitionLabels("ababcbacadefegdehijhklij");
    cout << "Test 1: ";
    for (int x : res1) cout << x << " ";
    cout << "(expected 9 7 8)" << endl;

    // 测试用例 2：全部不重复
    vector<int> res2 = sol.partitionLabels("abc");
    cout << "Test 2: ";
    for (int x : res2) cout << x << " ";
    cout << "(expected 1 1 1)" << endl;

    // 测试用例 3：全部相同
    vector<int> res3 = sol.partitionLabels("aaaa");
    cout << "Test 3: ";
    for (int x : res3) cout << x << " ";
    cout << "(expected 4)" << endl;

    return 0;
}
