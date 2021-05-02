/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
			unordered_map<int, int> count;

			for(auto elem : wall){
				int n = elem.size();
				int sum = 0;

				for(int i = 0; i < n - 1; ++i){
					sum += elem[i];
					count[sum] += 1;
				}
			}
			int max_count = 0;
			for(auto& [_, num] : count){
				max_count = max(max_count, num);
			}
		return wall.size() - max_count;
    }
};
// @lc code=end
