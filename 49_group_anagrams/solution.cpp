/**
 * 49. 字母异位词分组 (Group Anagrams)
 * 中等
 * 标签: 哈希表、排序、字符串
 *
 * 思路: 字母异位词排序后得到的字符串相同，以此作为哈希表的 key，
 *       原字符串加入对应的 vector。最后把所有 vector 收集起来即可。
 * 时间 O(n * k log k)：n 个字符串，每个长 k 的串排序
 *      (也可对每个串统计 26 字母频次作为 key，则 O(n * k))
 * 空间 O(n * k)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp; // 排序后的串 -> 原串组
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // 异位词排序后相同
            mp[key].push_back(s);
        }
        vector<vector<string>> res;
        for (auto& [key, group] : mp) { // C++17 结构化绑定
            res.push_back(move(group)); // move 避免拷贝
        }
        return res;
    }
};

int main() {
    Solution sol;

    // 测试用例 1
    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res1 = sol.groupAnagrams(strs1);
    cout << "测试1:" << endl;
    for (const auto& group : res1) {
        cout << "  [";
        for (size_t i = 0; i < group.size(); i++) {
            cout << group[i] << (i + 1 == group.size() ? "" : ", ");
        }
        cout << "]" << endl;
    }
    // 期望: 3 组，分别是 {"eat","tea","ate"}, {"tan","nat"}, {"bat"}

    // 测试用例 2
    vector<string> strs2 = {""};
    auto res2 = sol.groupAnagrams(strs2);
    cout << "测试2 组数: " << res2.size() << ", 首元素: \"" << res2[0][0] << "\"" << endl;
    // 期望: 1 组 ["" ]

    // 测试用例 3
    vector<string> strs3 = {"a"};
    auto res3 = sol.groupAnagrams(strs3);
    cout << "测试3 组数: " << res3.size() << ", 首元素: \"" << res3[0][0] << "\"" << endl;
    // 期望: 1 组 ["a"]

    return 0;
}
