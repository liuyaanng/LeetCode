/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
			vector<int> ans;
			for(int i = 0; i < nums.size(); ++i){
				int num = abs(nums[i]);
				if(nums[num - 1] > 0){
					nums[num - 1] *= -1;
				} else {
					ans.push_back(num);
				}
			}
			return ans;
		}
};
// @lc code=end
