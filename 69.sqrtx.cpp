/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */


// class Solution {
// public:
//     int mySqrt(int x) {
// 			if(x==0) return x;
//
// 			int left=1, right=x, mid=0, sqrt=0;
// 			while(left <= right){
// 				mid = (right - left) / 2 + left;
// 				// cout << mid << endl;
// 				sqrt = x / mid;
// 				if(sqrt == mid){
// 					return mid;
// 				}else if(sqrt > mid){
// 					left = mid + 1;
// 				}else{
// 					right = mid - 1;
// 				}
// 			}
// 			return right;
//     }
// };
// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
			long n = x;
			while( n * n > x ){
				n = (n + x / n) / 2;
			}
			return n;
    }
};
// @lc code=end
