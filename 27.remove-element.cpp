/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
			if(nums.empty()) return 0;
			int left = 0, right = nums.size();
			while(left < right){
				if(nums[left] == val){
					nums[left] = nums[--right];
				} else {
					++left;
				}
			}
			return left;
    }
};
// @lc code=end
