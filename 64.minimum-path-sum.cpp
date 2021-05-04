/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
			if(grid.size() == 0 || grid[0].size() == 0){
				return 0;
			}
			int r = grid.size(), c = grid[0].size();
			vector<vector<int>> dp(r, vector<int>(c));
			dp[0][0] = grid[0][0];
			for(int i = 1; i < r; ++i){
				dp[i][0] = dp[i - 1][0] + grid[i][0];
			}

			for(int i = 1; i < c; ++i){
				dp[0][i] = dp[0][i - 1] + grid[0][i];
			}

			for(int i = 1; i < r; ++i){
				for(int j = 1; j < c; ++j){
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
				}
			}
			return dp[r - 1][c - 1];
    }
};
// @lc code=end
