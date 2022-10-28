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
  TreeNode* invertTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (! q.empty()) {
      int level_size = q.size();
      while (level_size > 0) {
        TreeNode* cur_node = q.front();
        q.pop();
        if (cur_node != nullptr) {
          swap(cur_node->left, cur_node->right);
          q.push(cur_node->left);
          q.push(cur_node->right);
        }
        level_size--;
      }
    }
    return root;
  }
};

/* Runtime: 5 ms, faster than 29.24% of C++ online submissions for Invert Binary Tree.
 * Memory Usage: 9.7 MB, less than 80.68% of C++ online submissions for Invert Binary Tree.
 */

