/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
			if(intervals.empty()){
				return 0;
			}
			int size = intervals.size();
			sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){
					return a[1] < b[1];
					});
			int total = 0, prev = intervals[0][1];
			for(int i = 1; i < size; ++i){
				if(intervals[i][0] < prev){
					++total;
				}
				else{
					prev = intervals[i][1];
				}
			}
			return total;
    }
};
// @lc code=end
