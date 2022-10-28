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
    if (cur_node->left != nullptr) {
      tree_walker(cur_node->left, result);
    }
    result.push_back(cur_node->val);
    if (cur_node->right != nullptr) {
      tree_walker(cur_node->right, result);
    }
  }
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;
    tree_walker(root, result);
    return result;
  }
};

/* Runtime: 4 ms, faster than 44.23% of C++ online submissions for Binary Tree Inorder Traversal.
 * Memory Usage: 8.5 MB, less than 29.47% of C++ online submissions for Binary Tree Inorder Traversal.
 */

