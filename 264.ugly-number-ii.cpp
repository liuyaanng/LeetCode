/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
			if(n == 1) return n;
			long long count = 1, num; 
			while(n > 1){
				++count;
				num = count;
				while(num > 1){
					if(num % 2 == 0){
						num /= 2;
					} else if (num % 3 == 0){
						num /= 3;
					} else if (num % 5 == 0){
						num /= 5;
					} else {
						break;
					}
				}
				if(num == 1){
					--n;
				}
			}
			return count;
    }
};
// @lc code=end
