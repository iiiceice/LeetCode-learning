/**
 * 583. 两个字符串的删除操作
 * 难度：中等
 * 标签：动态规划、字符串
 *
 * 思路：dp[i][j] 表示 word1[0..i-1] 和 word2[0..j-1] 的最长公共子序列长度。
 *       最终答案 = len1 + len2 - 2 * dp[len1][len2]
 *       （公共子序列不用删，其余全删掉）
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return m + n - 2 * dp[m][n];
    }
};

int main() {
    Solution sol;

    cout << "Test 1: " << sol.minDistance("sea", "eat") << " (expected 2)" << endl;
    cout << "Test 2: " << sol.minDistance("leetcode", "etco") << " (expected 4)" << endl;
    cout << "Test 3: " << sol.minDistance("abc", "abc") << " (expected 0)" << endl;

    return 0;
}
