/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
			for(int i = 0; i < nums.size(); ++i){
				int temp = abs(nums[i]);
				if(nums[temp] < 0){
					return temp;
				} else {
					nums[temp] *= -1;
				}
			}
			return -1;
    }
};
// @lc code=end
