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
 private:
  void worker(TreeNode* cur_node) {
    if (cur_node == nullptr) return;
    swap(cur_node->left, cur_node->right);
    worker(cur_node->left);
    worker(cur_node->right);
  }
 public:
  TreeNode* invertTree(TreeNode* root) {
    worker(root);
    return root;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Invert Binary Tree.
 * Memory Usage: 9.8 MB, less than 38.49% of C++ online submissions for Invert Binary Tree.
 */

