/**
 * 139. 单词拆分 (Word Break)
 * 中等
 * 标签: 动态规划
 *
 * 思路: dp[i] 表示 s[0..i-1] 能否被字典拼出
 *       对每个位置 i，尝试所有 j < i：
 *       如果 dp[j]=true 且 s[j..i-1] 在字典里，则 dp[i]=true
 * 时间 O(n^2)，空间 O(n)
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // 空串默认可以拼出

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break; // 只要能拼出就行，不用继续试
                }
            }
        }
        return dp[n];
    }
};

int main() {
    Solution sol;

    vector<string> dict1 = {"leet", "code"};
    cout << sol.wordBreak("leetcode", dict1) << endl;  // 1

    vector<string> dict2 = {"apple", "pen"};
    cout << sol.wordBreak("applepenapple", dict2) << endl;  // 1

    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << sol.wordBreak("catsandog", dict3) << endl;  // 0

    return 0;
}
