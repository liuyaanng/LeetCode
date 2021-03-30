/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
// 方法1: 两次二分
// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
// 			if(matrix.empty()) return false;
// 			int left = 0, right = matrix.size() - 1, mid, i; 
// 			while(left <= right){
// 				mid = right + left >> 1;
// 				if(matrix[mid][0] == target){
// 					return true;
// 				} else if(matrix[mid][matrix[mid].size() - 1] < target){
// 					left = mid + 1;
// 				}else{
// 					right = mid - 1;
// 				}
// 			}
// 			i = left;
// 			if(i >= matrix.size()) return false;
// 			left = 0;
// 			right = matrix[i].size() - 1;
// 			while(left <= right){
// 				mid = left + right >> 1;
// 				if(matrix[i][mid] == target){
// 					return true;
// 				}else if(matrix[i][mid] < target){
// 					left = mid + 1;
// 				}else{
// 					right = mid - 1;
// 				}
// 			}
//
// 			return false;
//     }
// };
// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
			if(matrix.empty()) return false;
			int m = matrix.size(), n = matrix[0].size();
			int left = 0, right = m * n - 1, mid;

			while(left <= right){
				mid = right + left >> 1;
				int x = matrix[mid / n][mid % n];
				if(x == target){
					return true;
				}else if(x < target){
					left = mid + 1;
				}else{
					right = mid - 1;
				}
			}
			return false;
    }
};
// @lc code=end
