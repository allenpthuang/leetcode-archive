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
  void worker(TreeNode* cur_node, int& prev, int& cur_min_diff) {
    if (cur_node == nullptr) {
      return;
    }
    worker(cur_node->left, prev, cur_min_diff);
    if (prev != -1) {
      cur_min_diff = min(cur_min_diff, cur_node->val - prev);
    }
    prev = cur_node->val;
    worker(cur_node->right, prev, cur_min_diff);
  }
 public:
  int getMinimumDifference(TreeNode* root) {
    int prev = -1;
    int cur_min_diff = INT_MAX;
    worker(root, prev, cur_min_diff);
    return cur_min_diff;
  }
};

/* Runtime: 33 ms, faster than 24.27% of C++ online submissions for Minimum Absolute Difference in BST.
 * Memory Usage: 25.1 MB, less than 78.68% of C++ online submissions for Minimum Absolute Difference in BST.
 */

