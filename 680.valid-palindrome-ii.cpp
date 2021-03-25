/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
			int count=1, left = 0, right = s.size() - 1;
			while(left < right){
				if(s[left] == s[right]){
					++left;
					--right;
				} else return (isvailed(s, left + 1, right) || isvailed(s, left, right - 1));
			}
			return true;
		}
		bool isvailed(string s, int left, int right){
			while(left < right){
				if(s[left] == s[right]){
					++left;
					--right;
				}else return false;
				return true;
			}
		}
};
// @lc code=end
