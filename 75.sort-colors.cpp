/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
			int left = 0, right = nums.size(), i = 0;
			while(i < right){
				if(nums[i] == 0){
						swap(nums[i], nums[left++]);
						++i;
				} else if(nums[i] == 1){
					++i;
				} else{
						swap(nums[i], nums[--right]);
				}
			}
    }
};
// @lc code=end
