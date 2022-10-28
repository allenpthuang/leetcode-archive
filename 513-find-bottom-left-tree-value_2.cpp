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
  int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    int result;
    while (! q.empty()) {
      int level_size = q.size();
      bool popped = false;
      while (level_size > 0) {
        TreeNode* cur_node = q.front();
        q.pop();
        if (cur_node != nullptr) {
          if (! popped) {
            result = cur_node->val;
            popped = true;
          }
          q.push(cur_node->left);
          q.push(cur_node->right);
        }
        level_size--;
      }
    }
    return result;
  }
};

/* Runtime: 22 ms, faster than 26.38% of C++ online submissions for Find Bottom Left Tree Value.
 * Memory Usage: 22 MB, less than 16.50% of C++ online submissions for Find Bottom Left Tree Value.
 */

