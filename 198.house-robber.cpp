/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
			int m = 0, n = 0;
			for(int i = 0; i < nums.size(); ++i){
				if(i % 2 == 0){
					n += nums[i];
				} else {
					m += nums[i];
				}
			}

			return max(m, n);
    }
};
// @lc code=end
