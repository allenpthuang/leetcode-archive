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
  vector<vector<int> > levelOrderBottom(TreeNode* root) {
    list<vector<int> > result;
    queue<TreeNode*> q;
    if (root != nullptr) q.push(root);
    while (! q.empty()) {
      vector<int> level_result;
      int walk_size = q.size();
      while (walk_size > 0) {
        TreeNode* cur_node = q.front();
        if (cur_node->left != nullptr) q.push(cur_node->left);
        if (cur_node->right != nullptr) q.push(cur_node->right);
        level_result.push_back(cur_node->val);
        q.pop();
        walk_size--;
      }
      result.push_front(level_result);
    }
    return vector<vector<int> > (result.begin(), result.end());
  }
};

/* Runtime: 7 ms, faster than 51.51% of C++ online submissions for Binary Tree Level Order Traversal II.
 * Memory Usage: 12.6 MB, less than 34.55% of C++ online submissions for Binary Tree Level Order Traversal II.
 */

