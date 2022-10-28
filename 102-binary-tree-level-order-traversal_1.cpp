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
  vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > result;
    queue<TreeNode*> q;
    if (root != nullptr) {
      q.push(root);
    } else {
      return result;
    }
    while (! q.empty()) {
      vector<int> level_result;
      int walk_size = q.size();
      while (walk_size > 0) {
        TreeNode* cur_node = q.front();
        if (cur_node->left != nullptr) {
          q.push(cur_node->left);
        }
        if (cur_node->right != nullptr) {
          q.push(cur_node->right);
        }
        level_result.push_back(cur_node->val);
        q.pop();
        walk_size--;
      }
      result.push_back(level_result);
    }
    return result;
  }
};

/* Runtime: 10 ms, faster than 13.84% of C++ online submissions for Binary Tree Level Order Traversal.
 * Memory Usage: 12.4 MB, less than 96.05% of C++ online submissions for Binary Tree Level Order Traversal.
 */

