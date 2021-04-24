/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
			vector<ListNode *> tmp;
			ListNode* prev = head;

			while(prev != nullptr){
				tmp.push_back(prev);
				prev = prev->next;
			}

			prev = head;
			int i = 0, j = tmp.size() - 1;
			while(i < j){
				tmp[i++]->next = tmp[j];
				if(i == j) break;
				tmp[j--]->next = tmp[i];
			}
			tmp[i]->next = nullptr;
    }
};
// @lc code=end
