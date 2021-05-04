/*
 * @lc app=leetcode.cn id=832 lang=cpp
 *
 * [832] 翻转图像
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
			stack<int> s;

			for(auto & img : image){
				for(int num : img){
					s.push(!num);
				}

				for(int & num : img){
					num = s.top();
					s.pop();
				}
			}
		return image;
    }
};
// @lc code=end
