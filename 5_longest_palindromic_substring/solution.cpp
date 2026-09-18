// 5. 最长回文子串 (Longest Palindromic Substring)
// 难度：中等
// 标签：双指针、中心扩展、动态规划

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
思路：中心扩展法
- 回文一定有一个"中心"，中心有两种情况：
  1. 单个字符（奇数长度回文，如 "aba"）
  2. 相邻两个字符之间（偶数长度回文，如 "abba"）
- 长度为 n 的字符串共有 2n-1 个中心（n 个字符 + n-1 个空隙）
- 对每个中心，向两边同步扩展，直到字符不相等或越界，记录最长的一次
- 时间 O(n^2)，空间 O(1)

扩展函数：从 left、right 出发向两边走，返回回文的起点 start 和长度 len。
奇数回文传 (i, i)，偶数回文传 (i, i+1)，两种情况统一处理。
*/

class Solution {
public:
    pair<int, int> expand(const string& s, int left, int right) {
        // 向两边扩展，越界或字符不相等时停下
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // 此时 s[left+1, right-1] 是回文，长度为 right - left - 1
        return {left + 1, right - left - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;  // 至少有一个字符
        for (int i = 0; i < (int)s.size(); i++) {
            // 奇数长度：中心是 s[i]
            auto [s1, l1] = expand(s, i, i);
            if (l1 > maxLen) { start = s1; maxLen = l1; }
            // 偶数长度：中心是 s[i] 和 s[i+1] 之间
            auto [s2, l2] = expand(s, i, i + 1);
            if (l2 > maxLen) { start = s2; maxLen = l2; }
        }
        return s.substr(start, maxLen);
    }
};

/*
解法二：二维动态规划（区间 DP）
- 定义：dp[i][j] 表示 s[i..j] 是否为回文（i <= j）
- 转移：dp[i][j] = (s[i] == s[j]) && (j - i < 3 || dp[i+1][j-1])
  - s[i] != s[j]：一定不是回文
  - s[i] == s[j]：长度 1/2/3 时必然是回文（j-i < 3），更长的要看去掉两端后是否回文
- 遍历顺序：i 从大到小、j 从小到大，保证算 dp[i][j] 时 dp[i+1][j-1] 已就绪
- 时间 O(n^2)，空间 O(n^2)
- 对比中心扩展：慢且费空间，但这套"区间从内向外"的框架是
  LC 516 最长回文子序列的基础，值得掌握。
*/
class SolutionDP {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) return s;
        // 用 vector<char> 而非 vector<bool>：后者按比特打包，
        // v[0] 返回代理对象而非 bool&，取元素引用会编译报错
        vector<vector<char>> dp(n, vector<char>(n, 0));
        int start = 0, maxLen = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 3 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                    if (j - i + 1 > maxLen) {
                        start = i;
                        maxLen = j - i + 1;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

int main() {
    Solution sol;
    SolutionDP solDp;
    string cases[] = {"babad", "cbbd", "a", "abcba", "accca", "abcdef"};
    string expect[] = {"bab/aba", "bb", "a", "abcba", "accca", "a"};
    for (int i = 0; i < 6; i++) {
        string r1 = sol.longestPalindrome(cases[i]);
        string r2 = solDp.longestPalindrome(cases[i]);
        bool ok = r1.size() == r2.size();  // 两解法长度必相同，串可能不同
        cout << cases[i] << ": 中心扩展=" << r1 << " DP=" << r2
             << " (期望 " << expect[i] << ")" << (ok ? " [一致]" : " [不一致!]") << endl;
    }
    return 0;
}
