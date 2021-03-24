/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
			// chars 存储t中对应字母出现的次数
			// flag 记录t中出现的字母
			vector<int> chars(128, 0);
			vector<bool> flag(128, false);
			for(int i=0; i<t.size(); ++i){
				flag[t[i]] = true;
				++chars[t[i]];
			}
			int count=0, left=0, min_left = 0, min_size = s.size() + 1;
			// count 代表滑动窗口中已包含t中字符的个数
			// min_left用于记录最小滑动窗口的左侧下标
			// min_size 用于记录最小滑动窗口大小
			for(int right=0; right<s.size(); ++right ){
				if(flag[s[right]]){
					if(--chars[s[right]]>=0){
						++count;
					}
					while(count==t.size()){
						// 更新最小滑动窗口
						if(right - left + 1 < min_size){
							min_left = left;
							min_size = right -left + 1;
						}
						// 若左边待滑动元素是t中元素,并且若滑动, 当前滑动窗口不再包含t中所有字符
						// 待滑动
						if(flag[s[left]] && ++chars[s[left]] > 0){
							--count;
						}
						// 执行滑动 
						//左侧向右滑动
						++left;
					}
				}
			}
			return min_size > s.size() ? "" : s.substr(min_left, min_size);
    }
};
// @lc code=end
