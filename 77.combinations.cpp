/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
class Solution {
public:
		vector<vector<int>> ans;
		vector<int> path;
    vector<vector<int>> combine(int n, int k) {
			dfs(1, n, k);
			return ans;
		}

		void dfs(int pos, int n, int k){
			if(path.size() + (n - pos + 1) < k) return;

			if(path.size() == k){
				ans.push_back(path);
				return;
			}

			path.push_back(pos);
			dfs(pos + 1, n, k);
			path.pop_back();

			dfs(pos + 1, n, k);
		}
};
// @lc code=end
