/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */

// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

			for (auto& num : nums) {
				int pos = abs(num) - 1;
				if(nums[pos] > 0){
					nums[pos] = -nums[pos];
				}
			}

			vector<int> ans;

			for(int i = 0; i < nums.size(); ++i){
				if(nums[i] > 0){
					ans.push_back(i + 1);
				}
			}
		return ans;
    }
};
// @lc code=end
