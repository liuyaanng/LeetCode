/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
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
		int ans;
    int diameterOfBinaryTree(TreeNode* root) {
			ans = 0;
			len(root);

			return ans - 1;

    }

		int len(TreeNode* root){
			if(root == nullptr) return 0;

			int left_len = len(root->left);
			int right_len = len(root->right);

			ans = max(ans, left_len + right_len + 1);
			return max(left_len, right_len) + 1;
		}
};
// @lc code=end
