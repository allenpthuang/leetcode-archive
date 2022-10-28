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
  bool isCompleteTree(TreeNode* root) {
    vector<TreeNode*> bfs;
    
    bfs.push_back(root);
    for (int i = 0; i < bfs.size(); i++) {
      TreeNode* cur_node = bfs[i];
      if (cur_node != nullptr) {
        bfs.push_back(cur_node->left);
        bfs.push_back(cur_node->right);
      }
    }
    bool met_null = false;
    for (const auto& node : bfs) {
      if (node == nullptr) {
        met_null = true;
      } else if (met_null) {
        return false;
      }
    }
    return true;
  }
};

/* Runtime: 4 ms, faster than 80.36% of C++ online submissions for Check Completeness of a Binary Tree.
 * Memory Usage: 10.8 MB, less than 5.20% of C++ online submissions for Check Completeness of a Binary Tree.
 */


