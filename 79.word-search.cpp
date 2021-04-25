/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
		vector<int> direction{-1, 0, 1, 0 ,-1};
    bool exist(vector<vector<char>>& board, string word) {
			int count = 0, max_count = 0, m = board.size(), n = board[0].size();
			vector<vector<bool>> used(m, vector<bool>(n, false));
			for(int i = 0; i < board.size(); ++i){
				for(int j = 0; j < board[0].size(); ++j){
					backtrack(board, word, used, count, max_count, i, j);
				}
			}

			return max_count == word.size();
    }

		void backtrack(vector<vector<char>>& board, string word, vector<vector<bool>>& used, int& count, int& max_count, int r, int c){

			if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[count]) return;

			if(used[r][c] || max_count == word.size()) return;
			
			if(board[r][c] == word[count]){
				++count;
				used[r][c] = true;
				max_count = max(max_count, count);
				for(int k = 0; k < 4; ++k){
					int x = r + direction[k], y = c + direction[k + 1];
					backtrack(board, word, used, count, max_count, x, y);
				}
				--count;
				used[r][c] = false;
			}



				
			}
};
// @lc code=end
