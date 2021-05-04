/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x) {
			long ans = 0;
			int temp = abs(x);
			while(temp > 0){
				if(ans < INT_MIN / 10 || ans > INT_MAX / 10) return 0;
				ans = ans * 10 + temp % 10;
				temp /= 10;
			}
			return x >= 0 ? ans : (0 - ans);
    }
};
// @lc code=end
