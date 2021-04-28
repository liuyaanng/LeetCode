/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
			if(c <= 2) return true;

			int begin = 0, end = sqrt(c);

			while(begin <= end){
				if(end * end == c - begin * begin ){
					return true;
				} else if(end * end < c - begin * begin){
					++begin;
				} else {
					--end;
				}
			}
			return false;
    }
};
// @lc code=end
