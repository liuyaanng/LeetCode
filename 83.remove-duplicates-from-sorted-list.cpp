/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
// 			if(!head) return head;
// 			ListNode* left = head;
// 			ListNode* right = head->next;
// 			while(left->next != nullptr){
// 				if(left->val == right->val){
// 					if(right->next != nullptr){
// 						right = right->next;
// 					}else {
// 						left->next=nullptr;
// 						break;
// 					}
// 				}else{
// 					left->next = right;
// 					left = right;
// 					right = left->next;
// 				}
// 			}
// 			return head;
//     }
// };
//
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
			if(!head) return head;
			ListNode* pos = head;
			while(pos->next){
				if(pos->val == pos->next->val){
						pos->next = pos->next->next;
				}else pos = pos->next;
			}
			return head;
    }
};
// @lc code=end
