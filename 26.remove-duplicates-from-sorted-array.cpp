/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
			if(nums.empty()) return 0;
			int slow = 0, fast = 0, len = nums.size();
			while(fast < nums.size()){
				if(nums[slow] == nums[fast]){
					++fast;
				} else {
					nums[++slow] = nums[fast];
				}
			}

			len = slow + 1;
			return len;

    }
};
// @lc code=end
