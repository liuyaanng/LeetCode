/*
 * @lc app=leetcode.cn id=897 lang=cpp
 *
 * [897] 递增顺序查找树
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
	TreeNode* resNode;
	void inorder(TreeNode* node){
		if(node == nullptr) return;

		inorder(node->left);

		resNode->right = node;
		node->left = nullptr;
		resNode = node;

		inorder(node->right);
	}
    TreeNode* increasingBST(TreeNode* root) {

			TreeNode* dummynode = new TreeNode(-1);
			resNode = dummynode;
			inorder(root);

			return dummynode->right;
    }
};
// @lc code=end
