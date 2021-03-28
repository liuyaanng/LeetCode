/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
// 方法1
// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
// 			if(nums.empty()) return vector<int> {-1, -1};
// 			int l = 0, r = nums.size() - 1, mid;
// 			int first_pos = -1, last_pos = -1;
// 			bool is_exist = false;
// 			while(l <= r){
// 				mid = l + (r - l) / 2;
// 				if(target == nums[mid]){
// 					first_pos = last_pos = mid;
// 					is_exist = true;
// 					break;
// 				} else if(target > nums[mid]){
// 					l = mid + 1;
// 				} else{
// 					r = mid - 1;
// 				}
// 			}
//
// 			if(is_exist){
// 				while(first_pos >= 1 && nums[first_pos - 1] == nums[first_pos]) --first_pos; 
// 				while(last_pos < nums.size() - 1 && nums[last_pos + 1] == nums[last_pos]) ++last_pos;
// 			}
// 			return vector<int> {first_pos, last_pos};
//
//     }
// };
//
// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
			if(nums.empty()) return vector<int> {-1, -1};
			int lower = lower_bound(nums, target);
			int upper = upper_bound(nums, target) - 1;

			if(lower == nums.size() || nums[lower] != target) return vector<int> {-1, -1};

			return vector <int> {lower, upper};

    }
		int lower_bound(vector<int>& nums, int target){
			int l = 0, r = nums.size(), mid;

			while(l < r){
				mid = l + (r - l) / 2;
				if(nums[mid] >= target){
					r = mid;
				} else{
					l = mid + 1;
				}
			}
			return l;
		}
		int upper_bound(vector<int>& nums, int target){
			int l = 0, r = nums.size(), mid;
			while(l < r){
				mid = l + (r - l) / 2;
				if(nums[mid] > target){
					r = mid;
				} else{
					l = mid + 1;
				}
			}
			return l;
		}
};
// @lc code=end
