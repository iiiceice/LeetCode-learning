/**
 * 118. 杨辉三角 (Pascal's Triangle)
 * 简单
 * 标签: 动态规划
 *
 * 思路: 第 i 行有 i 个元素，首尾为 1
 *       中间元素: triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j]
 * 时间 O(numRows^2)，空间 O(numRows^2)
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1); // 每行首尾都是1
            for (int j = 1; j < i; j++) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle;
    }
};

int main() {
    Solution sol;

    auto print = [](const vector<vector<int>>& t) {
        for (auto& row : t) {
            for (int x : row) cout << x << " ";
            cout << endl;
        }
        cout << "---" << endl;
    };

    cout << "numRows=1:" << endl;
    print(sol.generate(1));  // [[1]]

    cout << "numRows=5:" << endl;
    print(sol.generate(5));  // [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

    return 0;
}
