/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
			int n = matrix.size();
			
			//水平翻转
			for(int i = 0; i < n / 2; ++i){
				for(int j = 0; j < n; ++j){
					swap(matrix[i][j], matrix[n - i - 1][j]);
				}
			}
			//对角线翻转
			for(int i = 0; i < n; ++i){
				for(int j = i; j < n; ++j){
					swap(matrix[i][j], matrix[j][i]);
				}
			}
    }
};
// @lc code=end
