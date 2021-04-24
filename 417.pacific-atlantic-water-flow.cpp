/*
 * @lc app=leetcode.cn id=417 lang=cpp
 *
 * [417] 太平洋大西洋水流问题
 */

// @lc code=start
class Solution {
public:
	vector<int> direction{-1,0,1,0,-1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
			if(heights.size() == 0 || heights[0].size() == 0) return {};

			vector<vector<int>> ans;

			int m = heights.size(), n = heights[0].size();
			vector<vector<bool>> can_reach_p(m, vector<bool>(n, false)); //太平洋
			vector<vector<bool>> can_reach_a(m, vector<bool>(n, false)); //大西洋
			
			//左右
			for(int i = 0; i < m; ++i){
				dfs(heights, i, 0, can_reach_p);
				dfs(heights, i, n - 1, can_reach_a);
			}

			//上下
			for(int j = 0; j < n; ++j){
				dfs(heights, 0, j, can_reach_p);
				dfs(heights, m - 1, j, can_reach_a);
			}

			for(int i = 0; i < m; ++i){
				for(int j = 0; j < n; ++j){
					if(can_reach_p[i][j] && can_reach_a[i][j]){
						ans.push_back({i,j});
					}
				}
			}

			return ans;
    }

		void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& can_reach){
			// 递归结束条件
			if(can_reach[r][c]) return;
			
			//符合条件
			can_reach[r][c] = true;
			int x, y;
			for(int k = 0; k < 4; ++k){
				x = r + direction[k];
				y = c + direction[k + 1];

				if(x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size() && heights[x][y] >= heights[r][c]){
					dfs(heights, x, y, can_reach);
				}
			}

		}

};
// @lc code=end
