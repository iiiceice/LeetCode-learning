/**
 * 994. 腐烂的橘子
 * 难度：中等
 * 标签：BFS、矩阵
 *
 * 思路：多源 BFS。先把所有腐烂橘子入队，同时统计新鲜橘子数量。
 *       每一轮（一分钟）把队列中所有腐烂橘子向四周扩散，
 *       被感染的新鲜橘子变腐烂并入队。
 *       BFS 结束后若还有新鲜橘子，返回 -1，否则返回分钟数。
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0;

        int mins = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!q.empty()) {
            int size = q.size();
            bool rotted = false;
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front(); q.pop();
                for (auto& d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        rotted = true;
                        q.push({nr, nc});
                    }
                }
            }
            if (rotted) mins++;
        }

        return fresh == 0 ? mins : -1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {{2,1,1},{1,1,0},{0,1,1}};
    cout << "Test 1: " << sol.orangesRotting(grid1) << " (expected 4)" << endl;

    vector<vector<int>> grid2 = {{2,1,1},{0,1,1},{1,0,1}};
    cout << "Test 2: " << sol.orangesRotting(grid2) << " (expected -1)" << endl;

    vector<vector<int>> grid3 = {{0,2}};
    cout << "Test 3: " << sol.orangesRotting(grid3) << " (expected 0)" << endl;

    return 0;
}
