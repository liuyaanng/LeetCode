/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
		int Quick_Select(vector<int>& nums, int left, int right, int index){
			int qivotkey = randomPartition(nums, left, right);
			if(qivotkey == index){
				return nums[qivotkey];
			}else{
				return qivotkey < index ? Quick_Select(nums, qivotkey + 1, right, index) : Quick_Select(nums, left, qivotkey - 1, index);
			}
		}

		inline int randomPartition(vector<int>& nums, int left, int right){
			int i = rand() % (right - left + 1) + left;
			swap(nums[i], nums[right]);
			return partition(nums, left, right);
		}

		inline int partition(vector<int>& nums, int left, int right){
			int X = nums[right], i = left - 1;
			for(int j = left; j < right; ++j){
				if(nums[j] <= X){
					swap(nums[++i], nums[j]);
				}
			}
			swap(nums[i+1], nums[right]);
			return i+1;
		}
		int findKthLargest(vector<int>& nums, int k) {
			srand(time(0));
			return Quick_Select(nums, 0, nums.size()-1, nums.size()-k);
		}
};
// @lc code=end
