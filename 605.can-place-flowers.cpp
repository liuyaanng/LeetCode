/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
// 跳格法
// class Solution {
// public:
//     bool canPlaceFlowers(vector<int>& flowerbed, int n) {
// 			if(n == 0){
// 				return true;
// 			}
// 			int size = flowerbed.size();
// 			for(int i=0; i<size;){
// 				if(flowerbed[i] == 1){
// 					i += 2;
// 				}else if(i == size - 1 || flowerbed[i+1] == 0){
// 					// 若在最后一个则直接可以种
// 					n--;
// 					if(n == 0){
// 						return n == 0;
// 					}
// 					i+=2;
// 				}else{
// 					i+=3;
// 				}
// 			}
// 			return n == 0;
//     }
// };
// @lc code=start
// 首尾插0
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
			if(n == 0){
				return true;
			}
			flowerbed.insert(flowerbed.begin(), 0);
			flowerbed.insert(flowerbed.end(), 0);
			for(int i = 1; i < flowerbed.size() - 1; i++){
				if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
					n--;
					flowerbed[i] = 1;
					if(n == 0){
						return n == 0;
					}
				}
			}
			return n == 0;
    }
};
// @lc code=end
