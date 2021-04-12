/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution {
public:
	int quick_select(vector<int> & nums, int left, int right){
		int pivotkey = rand() % (right - left) + left;
		swap(nums[pivotkey], nums[left]);
		int pivot = nums[left];
		while(left < right){
			while(left < right && nums[right] <= pivot) --right;
			nums[left] = nums[right];
			while(left < right && nums[left] >= pivot) ++left;
			nums[right] = nums[left];
		}
		nums[left] = pivot;
		return left;
	}
		int findKthLargest(vector<int>& nums, int k) {
			int left = 0, right = nums.size() - 1, mid = 0, target = k - 1; // target 指第k大的数的索引
			while(left < right){
				mid = quick_select(nums, left, right);
				if(mid == target){
					return nums[mid];
				} else if (mid < target){
					left = mid + 1;
				} else {
					right = mid - 1;
				}
			}
			return nums[left];
		}
};
// @lc code=end
