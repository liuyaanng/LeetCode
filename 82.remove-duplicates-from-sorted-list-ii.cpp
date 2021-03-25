/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 */

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
			// 创建 dummy node , dummy->next = head
			ListNode* dummy = new ListNode(0, head);
			ListNode* pos = dummy;
			while(pos->next && pos->next->next){
				if(pos->next->val == pos->next->next->val){
					int x = pos->next->val;
					while(pos->next && pos->next->val == x){
						pos->next = pos->next->next;
					}
				}else{
					pos = pos->next;
				}
			}
			return dummy->next;
    }
};
// @lc code=end
