/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
			if(needle.empty()) return 0;
			if(haystack.empty()) return -1;
			int left = 0, right = 0;
			while(left < haystack.size()){
				if(haystack[left] == needle[0]){
					right = left;
					int i = 1;
					for(i; i < needle.size(); ++i){
						if(haystack[++right] != needle[i]){
							++left;
							break;
						}
					}
					if(i == needle.size()) return left;					
				} else {
					++left;
				}
			}			
			return -1;
    }
};
// @lc code=end
