/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
			int left = 0, right = numbers.size() - 1, sum;
			while(left < right){
				sum = numbers[left] + numbers[right];
				if(target == sum) break;
				if(target > sum) left++;
				else right--;
			}
			return vector<int>{left+1, right+1};
    }
};
// @lc code=end
