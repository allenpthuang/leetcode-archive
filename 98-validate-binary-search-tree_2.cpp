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
  bool in_order_walker(TreeNode* cur_node, TreeNode*& prev_node) {
    if (cur_node == nullptr) return true;
    if (! in_order_walker(cur_node->left, prev_node)) return false;
    if ((prev_node != nullptr) && prev_node->val >= cur_node->val) return false;
    prev_node = cur_node;
    return in_order_walker(cur_node->right, prev_node);
  }
  bool isValidBST(TreeNode* root) {
    TreeNode* prev_node = nullptr;
    return in_order_walker(root, prev_node);
  }
};

/* Runtime: 12 ms, faster than 80.92% of C++ online submissions for Validate Binary Search Tree.
 * Memory Usage: 21.7 MB, less than 71.54% of C++ online submissions for Validate Binary Search Tree.
 */

