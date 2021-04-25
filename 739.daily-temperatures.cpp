/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
			int n = T.size();
			vector<int> ans(n);
			stack<int> date;

			for(int i = 0; i < n; ++i){
				while(!date.empty()){
					int pre_date = date.top();
					if(T[i] <= T[pre_date]){
						break;
					}
					date.pop();
					ans[pre_date] = i - pre_date;
				}
				date.push(i);
			}

			return ans;

    }
};
// @lc code=end
