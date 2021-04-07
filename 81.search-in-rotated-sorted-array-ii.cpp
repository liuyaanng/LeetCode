/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
	bool Binary_search(vector<int> nums, int left, int right, int target){
		while(left <= right){
			int mid = left + right >> 1;
			if(nums[mid] == target){
				return true;
			} else if(nums[mid] > target){
				right = mid - 1;
			} else{
				left = mid + 1;
			}
		}
		return false;
	}
    bool search(vector<int>& nums, int target) {
			if(nums.empty()) return false;
			int count = 0;
			bool isexist = false;
			while(count < nums.size()-1 && nums[count] <= nums[count+1]) ++count;
			if(nums[0] == target){
				return true;
			} else if(nums[0]<target){
				isexist = Binary_search(nums, 0, count, target);
			} else{
				isexist = Binary_search(nums, count+1, nums.size()-1, target);
			}
			return isexist;
    }
};
// @lc code=end
//
// 二分
// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
// 			int left = 0, right = nums.size() - 1;
// 			while(left <= right){
// 				int mid = left + right >> 1;
// 				if(nums[mid] == target) return true;
// 				if(nums[left] == nums[mid])
// 				{
// 					++left;
// 				}else if(nums[mid] <= nums[right])
// 				{
// 					if(target > nums[mid] && target <= nums[right]){
// 						left = mid + 1;
// 					} else {
// 						right = mid - 1;
// 					}
// 				} else {
// 					if(target < nums[mid] && target >= nums[left]){
// 						right = mid - 1;
// 					} else {
// 						left = mid + 1;
// 					}
// 				}
// 			}
// 			return false;
//     }
// };
