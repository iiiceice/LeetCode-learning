/**
 * 200. 岛屿数量
 * 难度：中等
 * 标签：DFS、BFS、并查集、矩阵
 *
 * 思路：遍历网格，遇到 '1' 就是一个新岛屿，计数 +1，
 *       然后 DFS 把连通的 '1' 全部变成 '0'（沉岛），避免重复计数。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    dfs(grid, i, j, m, n);
                }
            }
        }
        return count;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') return;
        grid[i][j] = '0';
        dfs(grid, i + 1, j, m, n);
        dfs(grid, i - 1, j, m, n);
        dfs(grid, i, j + 1, m, n);
        dfs(grid, i, j - 1, m, n);
    }
};

int main() {
    Solution sol;

    vector<vector<char>> grid1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    cout << "Test 1: " << sol.numIslands(grid1) << " (expected 1)" << endl;

    vector<vector<char>> grid2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << "Test 2: " << sol.numIslands(grid2) << " (expected 3)" << endl;

    return 0;
}
