/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
			//保存每个数字出现的次数, key: 数字, value: 出现次数
			unordered_map<int, int> counts;
			//出现最多的次数
			int max_count = 0;
			for(const int num : nums){
				max_count = max(max_count, ++counts[num]);
			}

			vector<vector<int>> buckets(max_count + 1);
			for(const auto elem : counts){
				buckets[elem.second].push_back(elem.first);
			}
			
			vector<int> ans;
			for(int i = max_count; i > 0 && ans.size() < k; --i){
				for(const auto elem : buckets[i]){
					ans.push_back(elem);
					if(ans.size() > k) break;
				}
			}
			return ans;


    }
};
// @lc code=end
