/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
			if(points.empty()){
				return 0;
			}
			sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b){
					return a[1] < b[1];
					});
			vector<int> point = points[0];
			int count = 1;
			for(int i=1; i < points.size(); ++i){
				if(point[1] < points[i][0]){
					point = points[i];
					count++;
				}
			}
			return count;
    }
};
// @lc code=end
