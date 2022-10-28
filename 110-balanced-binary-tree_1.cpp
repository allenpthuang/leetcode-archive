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
  int get_height(TreeNode* cur_node) {
    if (cur_node == nullptr) {
      return 0;
    }
    int lh = get_height(cur_node->left);
    if (lh == - 1) {
      return -1;
    }
    int rh = get_height(cur_node->right);
    if (rh == -1) {
      return -1;
    }
    if (abs(lh - rh) > 1) {
      return -1;
    }
    return max(lh, rh) + 1;
  }
  bool isBalanced(TreeNode* root) {
    int h = get_height(root);
    if (h == -1) {
      return false;
    } else {
      return true;
    }
  }
};

/* Runtime: 23 ms, faster than 30.15% of C++ online submissions for Balanced Binary Tree.
 * Memory Usage: 21.1 MB, less than 26.46% of C++ online submissions for Balanced Binary Tree.
 */

