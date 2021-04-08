/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
			int len = nums.size();
			if(len <=2) return len;
			int slow = 2, fast = 2;
			while(fast < nums.size()){
				if(nums[slow - 2] != nums[fast]){
					nums[slow] = nums[fast];
					++slow;
				}
				++fast;
			}
			return slow;
    }
};
// @lc code=end
