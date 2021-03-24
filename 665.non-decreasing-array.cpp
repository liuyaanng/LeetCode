/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */

// @lc code=start
class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int size = nums.size();
		bool flag = nums[0] <= nums[1] ? true : false;
		for(int i = 1; i < size - 1; ++i){
			if(nums[i] > nums[i+1]){
				if(flag){
					if(nums[i-1] > nums[i+1]){
						nums[i+1] = nums[i];
					}else{
						nums[i] = nums[i+1];
					}
					flag = false;
				}
				else{
					return false;
				}
			}
		}
		return true;
	}
};
// @lc code=end
