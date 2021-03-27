/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
			if(!head || k == 0) return head;
			ListNode* fast = head;
			ListNode* slow = head;
			int count = 1;
			while(fast->next){
				fast = fast->next;
				++count;
			}
			fast->next = head;
			k = count - k % count;
			while(k-- > 1) slow = slow->next;
			head = slow->next;
			slow->next = nullptr;
			return head;
		}
};
// @lc code=end
