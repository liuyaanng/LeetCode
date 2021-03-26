/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
			int s_size = s.size(), d_size = dictionary.size();
			int s_index = 0, index = 0, longest_index = 0;
			bool isexit = false;
			vector<int> word_count(d_size, 0);


			for(int d_index = 0; d_index < d_size; ++d_index){
				string d_word = dictionary[d_index];
				while(index < d_word.size() && s_index < s_size){
					if(s[s_index] == d_word[index]){
						++s_index;
						++index;
					}else{
						++s_index;
					}
				}
				if(s_index <= s_size && index >= d_word.size()){
					word_count[d_index] = dictionary[d_index].size();
					isexit = true;
				}
				s_index = 0;
				index = 0;
			}
			for(int i=0; i<word_count.size();++i){
				if(word_count[longest_index] < word_count[i] || (word_count[longest_index] == word_count[i] && dictionary[longest_index] > dictionary[i])){
						longest_index = i;
				}
			}
			return isexit ? dictionary[longest_index] : "";
    }
};
// @lc code=end
