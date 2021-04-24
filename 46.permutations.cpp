/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
	void backtrack(vector<vector<int>>& ans, vector<int>& output, int first, int len){
		if(first == len){
			ans.push_back(output);
			return;
		}

		for(int i = first; i < len; ++i){
			swap(output[i], output[first]);
			backtrack(ans, output, first + 1, len);
			swap(output[i], output[first]);
		}


	}
    vector<vector<int>> permute(vector<int>& nums) {
			vector<vector<int>> ans;
			backtrack(ans, nums, 0, nums.size());
			return ans;


    }
};
// @lc code=end
