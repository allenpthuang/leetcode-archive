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
  int maxDepth(TreeNode* root) {
    int cur_depth = 0;
    bool level_recorded = false;
    queue<TreeNode*> q;
    q.push(root);
    while (! q.empty()) {
      int walk_size = q.size();
      while (walk_size > 0) {
        TreeNode* cur_node = q.front();
        q.pop();
        if (cur_node != nullptr) {
          if (! level_recorded) {
            cur_depth++;
            level_recorded = true;
          }
          q.push(cur_node->left);
          q.push(cur_node->right);
        }
        walk_size--;
      }
      level_recorded = false;
    }
    return cur_depth;
  }
};

/* Runtime: 5 ms, faster than 89.85% of C++ online submissions for Maximum Depth of Binary Tree.
 * Memory Usage: 18.9 MB, less than 14.30% of C++ online submissions for Maximum Depth of Binary Tree.
 */

