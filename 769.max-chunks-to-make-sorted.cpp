/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
			int chunk = 0, max_curr = 0;
			for(int i = 0; i < arr.size(); ++i){
				max_curr = max(max_curr, arr[i]);
				if(max_curr == i) ++chunk;
			}
			return chunk;
    }
};
// @lc code=end
