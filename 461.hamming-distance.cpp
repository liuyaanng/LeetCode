/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
// class Solution {
// public:
//     int hammingDistance(int x, int y) {
// 			int z = x ^ y;
// 			int distance = 0;
// 			while(z){
// 				distance += z & 1;
// 				z = z >> 1;
// 			}
// 			return distance;
//     }
// };
// class Solution {
// public:
//     int hammingDistance(int x, int y) {
// 			int z = x xor y;
// 			int distance = 0;
// 			while(z){
// 				distance += 1;
// 				z = z & (z - 1);
// 			}
// 			return distance;
//     }
// };
class Solution {
public:
    int hammingDistance(int x, int y) {
			return bitset<32>(x ^ y).count();
    }
};
// @lc code=end
