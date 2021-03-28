/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
			int left = 0, right = nums.size() - 1;
			while(left <= right){
				int mid = left + right >> 1;
				if(nums[mid] == target) return true;
				if(nums[left] == nums[mid])
				{
					++left;
				}else if(nums[mid] <= nums[right])
				{
					if(target > nums[mid] && target <= nums[right]){
						left = mid + 1;
					} else {
						right = mid - 1;
					}
				} else {
					if(target < nums[mid] && target >= nums[left]){
						right = mid - 1;
					} else {
						left = mid + 1;
					}
				}
			}
			return false;
    }
};
// @lc code=end
