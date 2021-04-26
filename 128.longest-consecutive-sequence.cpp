/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
			if(nums.empty()) return 0;
			int max_count = 1, count = 1;
			quick_sort(nums, 0, nums.size() - 1);
			for(int i = 1; i < nums.size(); ++i){
				if(nums[i] - nums[i - 1] == 1){
					++count;
				} else if(nums[i] != nums[i - 1]){
					count = 1;
				}
				max_count = max(max_count, count);
			}
			return max_count;
    }

		void quick_sort(vector<int>& nums, int left, int right){
			if(left < right){
				int i = left, j = right;
				int pivot_key = rand() % (right - left) + left;
				swap(nums[pivot_key], nums[left]);
				int pivot = nums[left];
				while(left < right){
					while(left< right && nums[right] >= pivot) --right;
					nums[left] = nums[right];
					while(left < right && nums[left] <= pivot) ++left;
					nums[right] = nums[left];
				}
				
				nums[left] = pivot;

				quick_sort(nums, left + 1, j);
				quick_sort(nums, i, left - 1);
			}

		}
};
// @lc code=end
