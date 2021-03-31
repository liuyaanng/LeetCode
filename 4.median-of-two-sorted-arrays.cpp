/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
		
	int get_kth_element(vector<int>& nums1, vector<int> nums2, int k){
		// 分别设置指针
		int index1 = 0, index2 = 0;
		int size1 = nums1.size(), size2 = nums2.size();
		while(true){
			// 处理边界情况
			// nums1数组空
			if(index1 >= size1){
				return nums2[index2 + k - 1];
			}
			// nums2数组空
			if(index2 >= size2){
				return nums1[index1 + k - 1];
			}
			// k = 1
			if(k == 1){
				return min(nums1[index1], nums2[index2]);
			}

			//处理一般情况
			//
			int newindex1 = min(index1 + k / 2 - 1, size1 - 1);
			int newindex2 = min(index2 + k / 2 - 1, size2 - 1);

			int value1 = nums1[newindex1];
			int value2 = nums2[newindex2];

			if(value1<=value2){
				k = k - (newindex1 - index1 + 1);
				index1 = newindex1 + 1;
			}else{
				k = k - (newindex2 - index2 + 1);
				index2 = newindex2 + 1;
			}
		}

	}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

			int length = nums1.size() + nums2.size();
			
			//奇数长
			if(length % 2 == 1){
				return (double)get_kth_element(nums1, nums2, (length + 1) / 2);
			}else{
				return (get_kth_element(nums1, nums2, length / 2) + get_kth_element(nums1, nums2, length / 2 + 1)) / 2.0;
			}
    }
};
// @lc code=end
//
// 方法1.1
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// 			int pos1 = 0, pos2 = 0, index = 0;
// 			int size = nums1.size() + nums2.size();
// 			vector <int> added_nums(size, 0);
// 			while(pos1<nums1.size() && pos2<nums2.size()){
// 				if(nums1[pos1] <= nums2[pos2]){
// 					added_nums[index] = nums1[pos1];
// 					++pos1;
// 				}else{
// 					added_nums[index] = nums2[pos2];
// 					++pos2;
// 				}
// 				++index;
// 			}
//
// 			if(pos1 >= nums1.size() && pos2 < nums2.size()){
// 				while(pos2<nums2.size()){
// 					added_nums[index] = nums2[pos2];
// 					++pos2;
// 					++index;
// 				}
// 			}
//
// 			if(pos2 >= nums2.size() && pos1 < nums1.size()){
// 				while(pos1 < nums1.size()){
// 					added_nums[index] = nums1[pos1];
// 					++pos1;
// 					++index;
// 				}
// 			}
//
// 			// for(int i=0; i<added_nums.size(); ++i) cout << added_nums[i] << endl;
// 			int mid = added_nums.size() >> 1;
// 			return added_nums.size() % 2 == 0 ? (double) (added_nums[mid] + added_nums[mid - 1]) / 2 : added_nums[mid];
//     }
// };
//
// 使用sort函数
// class Solution {
// public:
//     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
// 			int size = nums1.size() + nums2.size();
// 			int i, j;
// 			vector <int> added_nums(size, 0);
// 			for(i=0; i<nums1.size(); ++i){
// 				added_nums[i] = nums1[i];
// 			}
// 			for(j=0; j<nums2.size();++j){
// 				added_nums[i+j] = nums2[j];
// 			}
// 			sort(added_nums.begin(), added_nums.end());
// 			int mid = added_nums.size() >> 1;
// 			return added_nums.size() % 2 == 0 ? (double)(added_nums[mid] + added_nums[mid-1]) / 2 : added_nums[mid];
//
//     }
// };
