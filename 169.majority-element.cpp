/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
			int ans = -1, count = 0;

			for(const int elem : nums){
				if(elem == ans){
					++count;
				} else if(--count < 0){
					ans = elem;
					count = 1;
				}
			}
			return ans;
    }
};
// @lc code=end
