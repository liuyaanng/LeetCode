/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
			if(s.size() == 0) return s;
			unordered_map<char, int> str_counts;
			int max_count = 0;

			for(const char& elem : s){
				max_count = max(max_count, ++str_counts[elem]);
			}
			vector<vector<char>> buckets(max_count + 1);
			for(auto elem : str_counts){
				buckets[elem.second].push_back(elem.first);
			}
			
			string ans;

			for(int i = max_count; i > 0; --i){
				for(auto elem : buckets[i]){
					int n = i;
					while(n > 0){
						ans.push_back(elem);
						--n;
					}
				}
			}

			return ans;

    }
};
// @lc code=end
