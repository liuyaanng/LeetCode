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
			int ans = 0;
			unordered_set<int> hash;
			for (auto elem : nums) {
				hash.insert(elem);
			}

			while(!hash.empty()){
				int pos = *(hash.begin());
				hash.erase(pos);
				int next = pos + 1, pre = pos - 1;

				while(hash.count(next)){
					hash.erase(next++);
				}
				while(hash.count(pre)){
					hash.erase(pre--);
				}
				ans = max(ans, next - pre - 1);
			}
			return ans;
		}
};
// @lc code=end
