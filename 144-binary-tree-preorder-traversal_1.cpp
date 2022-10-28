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
  void tree_walker(TreeNode* cur_node, vector<int>& result) {
    if (cur_node != nullptr) {
      result.push_back(cur_node->val);
      tree_walker(cur_node->left, result);
      tree_walker(cur_node->right, result);
    } else {
      return;
    }
  }
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    TreeNode* cur_node = root;
    tree_walker(cur_node, result);
    return result;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
 * Memory Usage: 8.3 MB, less than 75.59% of C++ online submissions for Binary Tree Preorder Traversal.
 */


