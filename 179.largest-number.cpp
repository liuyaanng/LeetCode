/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 */

// @lc code=start
class Solution {
public:
		void quick_sort(vector<int> & nums, int left, int right){
			int i = left, j = right;
			if(left < right){
					int pivotkey = rand() % (right - left + 1) + left;
					swap(nums[left], nums[pivotkey]);
					int pivot = nums[left];
					while(left < right){
						while(left < right && to_string(nums[right]) + to_string(pivot) <= to_string(pivot) + to_string(nums[right])) --right;
						nums[left] = nums[right];
						while(left < right && to_string(nums[left]) + to_string(pivot) >= to_string(pivot) + to_string(nums[left])) ++left;
						nums[right] = nums[left];
					}
					nums[left] = pivot;
					pivotkey = left;
					quick_sort(nums, i, pivotkey - 1);
					quick_sort(nums, pivotkey + 1, j);
				}
			}
    string largestNumber(vector<int>& nums) {
			string res = "";
			quick_sort(nums, 0, nums.size() - 1);
			if(nums[0] > 0){
				for(int i = 0; i < nums.size(); ++i){
					res += to_string(nums[i]);
				}
			} else {
				return "0";
			}
			return res;
    }
};
// @lc code=end
