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
    if (root == nullptr) {
      return 0;
    }
    int level = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (! q.empty()) {
      level++;
      auto walk_size = q.size();
      while (walk_size > 0) {
        TreeNode* cur_node = q.front();
        q.pop();
        walk_size--;
        if (cur_node->left != nullptr) {
          q.push(cur_node->left);
        }
        if (cur_node->right != nullptr) {
          q.push(cur_node->right);
        }
      }
      
    }
    return level;
  }
};

/**
 * Idea: do level-by-level traversal.
 */
