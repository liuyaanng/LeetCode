/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
			vector<int> ans;

			if(root == nullptr) return ans;
			stack<TreeNode*> s;
			TreeNode* node = root;

			while(!s.empty() || node != nullptr){
				while(node != nullptr){
					ans.emplace_back(node->val);
					s.emplace(node);
					node = node->left;
				}

				node = s.top();
				s.pop();
				node = node->right;
			}
			return ans;
    }
};
// @lc code=end
