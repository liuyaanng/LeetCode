/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
// 最低有效位
// class Solution {
// public:
//     vector<int> countBits(int num) {
// 			vector<int> result(num + 1);
// 			int highbit = 0;
// 			for(int x=1; x <= num; x++){
// 				result[x] = result[x>>1] + (x & 1);
// 			}
// 			return result;
//     }
// };
// 最低设置位
class Solution {
public:
    vector<int> countBits(int num) {
			vector<int> result(num + 1);
			int highbit = 0;
			for(int x=1; x <= num; x++){
				result[x] = result[x&(x-1)] +1;
			}
			return result;
    }
};
// 最高有效位
// class Solution {
// public:
//     vector<int> countBits(int num) {
// 			vector<int> result(num + 1);
// 			int highbit = 0;
// 			for(int x=1; x <= num; x++){
// 				if((x & (x - 1)) == 0){
// 					highbit = x;
// 				}
// 				result[x] = result[x - highbit] + 1;
// 			}
// 			return result;
//     }
// };
// // class Solution {
// public:
// 	int count_ones(int x){
// 		int count = 0;
// 		while(x){
// 			x &= (x - 1);
// 			count++;
// 		}
// 		return count;
// 	}
//     vector<int> countBits(int num) {
// 			vector<int> result(num + 1);
// 			for(int x=0; x <= num; x++){
// 				result[x] = count_ones(x);
// 			}
// 			return result;
//     }
// };
// @lc code=end
