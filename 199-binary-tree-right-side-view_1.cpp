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
  vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    queue<TreeNode*> q;
    if (root == nullptr) return result;
    q.push(root);
    
    while (! q.empty()) {
      int walk_size = q.size();
      while (walk_size > 0) {
        TreeNode* cur_node = q.front();
        if (cur_node->left != nullptr) q.push(cur_node->left);
        if (cur_node->right != nullptr) q.push(cur_node->right);
        if (walk_size == 1) result.push_back(cur_node->val);
        q.pop();
        walk_size--;
      }
    }
    
    return result;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Right Side View.
 * Memory Usage: 12.1 MB, less than 20.47% of C++ online submissions for Binary Tree Right Side View.
 */

