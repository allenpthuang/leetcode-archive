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
  int minDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    int min_depth = 0;
    while (! q.empty()) {
      min_depth++;
      int level_size = q.size();
      while (level_size > 0) {
        TreeNode* cur_node = q.front();
        q.pop();
        if (cur_node != nullptr) {
          if (cur_node->left == nullptr && cur_node->right == nullptr) {
            return min_depth;
          } else {
            q.push(cur_node->left);
            q.push(cur_node->right);
          }
        }
        level_size--;
      }
    }
    return min_depth;
  }
};

/* Runtime: 311 ms, faster than 61.11% of C++ online submissions for Minimum Depth of Binary Tree.
 * Memory Usage: 144.7 MB, less than 72.82% of C++ online submissions for Minimum Depth of Binary Tree.
 */

