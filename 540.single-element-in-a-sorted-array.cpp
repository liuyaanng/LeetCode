/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
// 二分法
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
			int left=0, right = nums.size() -1, mid;
			while(left < right){
				mid = left + right >> 1;
				bool are_even = (right - mid) % 2 == 0; 
				if(nums[mid] == nums[mid + 1]){

					if(are_even){
						left = mid + 2;
					} else {
						right = mid - 1;
					}
				}else if(nums[mid] == nums[mid - 1]){
					if(are_even){
						right = right - 2;
					} else{
						left = left + 1;
					}
				}else{
					return nums[mid];
				}
			}

			return nums[right];
    }
};
// @lc code=end
//
//暴力搜索
// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
// 			int i = 0;
// 			while(i<nums.size() - 1){
// 				if(nums[i] == nums[i+1]){
// 					i+=2;
// 				}else{
// 					return nums[i];
// 				}
// 			}
// 			return nums[i];
//     }
// };
