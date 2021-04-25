/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
			int left = *max_element(weights.begin(), weights.end()), right = accumulate(weights.begin(), weights.end(), 0);
			
			while(left < right){
				int mid = left + right >> 1;
				int need = 1, curr = 0;

				for (auto weight : weights) {
					if(curr + weight > mid){
						++need;
						curr = 0;
					}
					curr += weight;
				}

				if(need <= D){
					right = mid;
				} else {
					left = mid + 1;
				}
				
			}
			return left;
    }
};
// @lc code=end
