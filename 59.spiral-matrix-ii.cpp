/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
			vector<vector<int>> ans(n, vector<int>(n));
			int min_r = 0, min_c = 0, max_r = n - 1, max_c = n - 1, count = 0;
			bool flag_c_plus = false, flag_r_plus = true, flag_c_mu = false, flag_r_mu = false; // 为true代表改变的是什么

			while(count < n * n){
				if(flag_r_plus){
					for(int i = min_c; i <= max_c; ++i){
						cout << "flag_r_plus" << ',';
						++count;
						cout << count;
						ans[min_r][i] = count;
					}
					++min_r;
					flag_r_plus = false;
					flag_c_plus = true;
				}

				else if(flag_c_plus){
					for(int i = min_r; i <= max_r; ++i){
						cout << "flag_c_plus" << ',';
						++count;
						cout << count;
						cout << "i = " << i << ',' << "max_c  - 1 "  << (max_c - 1) << ',';
						ans[i][max_c] = count;
					}
					--max_c;
					flag_c_plus = false;
					flag_r_mu = true;
				}

				else if(flag_r_mu){
					for(int i = max_c; i > min_c; --i){
						cout << "flag_r_mu" << ',';
						++count;
						cout << count;
						ans[max_r][i] = count;
					}
					--max_r;
					flag_r_mu = false;
					flag_c_mu = true;
				}

				else if(flag_c_mu){
					for(int i = max_r; i > min_r; --i){
						cout << "flag_c_mu" << ',';
						++count;
						cout << count;
						ans[i][min_c] = count;
					}
					++min_c;
					flag_c_mu = false;
					flag_r_plus = true;
				}

			}

		return ans;
    }


};
// @lc code=end
