/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
	int count_ones(int x){
		int count = 0;
		while(x > 0){
			x &= (x - 1);
			count++;
		}
		return count;
	}
    vector<int> countBits(int num) {
			vector<int> result(num + 1);
			for(int x=0; x <= num; x++){
				result[x] = count_ones(x);
			}
			return result;
    }
};
// @lc code=end
