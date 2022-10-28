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
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    TreeNode* cur_node = root;
    TreeNode* prev_node;
    while (cur_node != nullptr) {
      prev_node = cur_node;
      if (cur_node->val > val) {
        cur_node = cur_node->left;
      } else {
        return new TreeNode(val, cur_node->left, prev_node->right);
      }
    }
    return new TreeNode(val);
  }
};

/* wrong answer */

