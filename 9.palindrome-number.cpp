/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
			if(x < 0 || (x != 0 && x % 10 == 0)) return false;

			int ans = 0;
			while(x > ans){
				ans = x % 10 + 10 * ans;
				x /= 10;
			}
			return x == ans || x == ans / 10;
    }
};
// @lc code=end
