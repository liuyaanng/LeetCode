/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int size = nums1.size() + nums2.size();
			int i, j;
			vector <int> added_nums(size, 0);
			for(i=0; i<nums1.size(); ++i){
				added_nums[i] = nums1[i];
			}
			for(j=0; j<nums2.size();++j){
				added_nums[i+j] = nums2[j];
			}
			sort(added_nums.begin(), added_nums.end());
			int mid = added_nums.size() >> 1;
			return added_nums.size() % 2 == 0 ? (double)(added_nums[mid] + added_nums[mid-1]) / 2 : added_nums[mid];

    }
};
// @lc code=end
