/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
		vector<int> direction{-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
			if(grid.empty() || grid[0].empty()) return 0;
			int max_area = 0;
			for (int i = 0; i < grid.size(); ++i) {
				for (int j = 0; j < grid[0].size(); ++j) {
						max_area = max(max_area, dfs(grid, i, j));
				}
			}
			return max_area;
    }

		int dfs(vector<vector<int>>& grid, int r, int c){
			if(r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0) return 0;
			grid[r][c] = 0; 
			return 1 + dfs(grid, r - 1, c) + dfs(grid, r + 1, c) + dfs(grid, r, c - 1) + dfs(grid, r, c + 1);
		}
};
// @lc code=end
