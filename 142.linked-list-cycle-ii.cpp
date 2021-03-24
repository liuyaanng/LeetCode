/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * <0;21;7M[142] 环形链表 II
 */


// 快慢指针
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
// 			ListNode *fast = head, *slow = head;
// 			do{
// 				if(!fast || !fast->next) return nullptr;
// 				fast = fast->next->next;
// 				slow = slow->next;
// 			}while(fast != slow);
//
// 			fast = head;
// 			while(fast!=slow){
// 				fast = fast->next;
// 				slow = slow->next;
// 			}
// 			return fast;
//     }
// };
//

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//hashtable
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
			unordered_set<ListNode *> visited;
			while(head!=nullptr){
				if(visited.count(head)){
					return head;
				}
				visited.insert(head);
				head = head->next;
			}
			return nullptr;
		}
};
// @lc code=end
