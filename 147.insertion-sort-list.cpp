/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
			ListNode* dummynode = new ListNode();
			dummynode->next = head;
			ListNode* pos = head->next;
			ListNode* sorted = head;
			while(pos != nullptr){
				if(sorted->val <= pos->val){
					sorted = sorted->next;
				} else {
					ListNode* pre = dummynode;
					while(pre->next->val <= pos->val){
						pre = pre->next;
					}
					sorted->next = pos->next;
					pos->next = pre->next;
					pre->next = pos;
				}
				pos = sorted->next;
			}
			return dummynode->next;
    }
};
// @lc code=end
