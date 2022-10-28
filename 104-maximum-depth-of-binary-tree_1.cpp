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
  void worker(TreeNode* cur_node, int cur_depth, int& cur_max) {
    if (cur_node == nullptr) {
      return;
    }
    cur_max = max(cur_max, cur_depth);
    worker(cur_node->left, cur_depth + 1, cur_max);
    worker(cur_node->right, cur_depth + 1, cur_max);
  }
 public:
  int maxDepth(TreeNode* root) {
    int cur_depth = 0;
    int cur_max = 0;
    worker(root, cur_depth + 1, cur_max);
    return cur_max;
  }
};

/* Runtime: 19 ms, faster than 17.06% of C++ online submissions for Maximum Depth of Binary Tree.
 * Memory Usage: 18.9 MB, less than 56.90% of C++ online submissions for Maximum Depth of Binary Tree.
 */

