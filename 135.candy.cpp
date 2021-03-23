/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
		int size = ratings.size();
		if(size < 2){
			return size;
		}
		vector<int> num(size, 1);
		for(int i = 0; i < size - 1; ++i){
			if(ratings[i] < ratings[i+1]){
				num[i+1] = num[i] + 1;
			}
		}
		for(int j = size - 1; j > 0; --j){
			if(ratings[j] < ratings[j-1]){
				num[j-1] = max(num[j-1], num[j] + 1);
			}
		}
		return accumulate(num.begin(), num.end(), 0);
    }
};
// @lc code=end
