/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
			map<char, char> ch{{')', '('}, {'}', '{'}, {']', '['}};
			stack<char> temp;
			for(int i = 0; i < s.size(); ++i){
				if(temp.empty()){
					temp.push(s[i]);
				} else {
					if(ch[s[i]] == temp.top()){
						temp.pop();
					} else {
						temp.push(s[i]);
					}
				}
			}
			
			return temp.empty() ? true : false;

    }
};
// @lc code=end
