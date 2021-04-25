/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> ans;
			backtrack(nums, 0, ans);
			return ans;
    }


		// len是已经排列的数字的长度
		void backtrack(vector<int>& nums, int len, vector<vector<int>>& ans){
			if(len == nums.size() - 1){
				ans.push_back(nums);
				return;
			}
			for(int i = len; i < nums.size(); ++i){
				swap(nums[i], nums[len]);
				backtrack(nums, len + 1, ans);
				swap(nums[i], nums[len]);
			}
		}
};
// @lc code=end
