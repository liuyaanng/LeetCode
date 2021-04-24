/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * <0;32;13M[695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
		vector<int> direction{-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
			int m = grid.size(), n = m ? grid[0].size() : 0, area = 0, local_area = 0;
			for(int i = 0; i < m; ++i){
				for(int j = 0; j < n; ++j){
					if(grid[i][j] == 1){
						local_area = 1;
						//防止重复寻找
						grid[i][j] = 0;
						stack<pair<int, int>> island;
						island.push({i, j});

						while(!island.empty()){
							auto [r,c] = island.top();
							island.pop();
							for(int k = 0; k < 4; ++k){
								//分别向上下左右移动, 若存在岛屿,将其入栈, 即该处也可向其他方向移动来寻找. 
								int x = r + direction[k], y = c + direction[k + 1];
								if(x >= 0 && x < m && y >=0 && y < n && grid[x][y] == 1){
									grid[x][y] = 0;
									++local_area;
									island.push({x, y});
								}
							}
							area = max(area, local_area);
						}
					}
				}
			}
			return area;
    }
};
// @lc code=end
