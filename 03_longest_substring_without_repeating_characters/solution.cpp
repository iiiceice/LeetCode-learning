/**
 * 3. 无重复字符的最长子串 (Longest Substring Without Repeating Characters)
 * 难度：Medium
 * 标签：滑动窗口、哈希表
 *
 * 思路：维护一个滑动窗口 [left, right]，用哈希表记录每个字符最近出现的位置。
 * 右指针每遇到重复字符时，将左指针跳到该字符上次出现的下一位。
 * 过程中维护最大窗口长度即为答案。
 */

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last; // 字符 -> 最近出现的下标
        int left = 0, ans = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];
            if (last.count(c) && last[c] >= left) {
                left = last[c] + 1; // 左指针跳过重复字符
            }
            last[c] = right;
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    // 测试用例
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl; // 3 ("abc")
    cout << sol.lengthOfLongestSubstring("bbbbb") << endl;    // 1 ("b")
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;   // 3 ("wke")
    cout << sol.lengthOfLongestSubstring("") << endl;         // 0
    cout << sol.lengthOfLongestSubstring("au") << endl;       // 2

    return 0;
}
