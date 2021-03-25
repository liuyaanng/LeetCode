/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
			if(c<=2){
				return true;
			}
			long a = 0, b = sqrt(c);
			while(a<=b){
				if(b*b == c - a*a){
					return true;
				}else if(b*b < c - a*a){
					++a;
				}else{
					--b;
				}
			}
			return false;
    }
};
// @lc code=end
