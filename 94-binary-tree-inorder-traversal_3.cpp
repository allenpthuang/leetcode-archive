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
  void inorder_walker(TreeNode* cur_node, vector<int>& result) {
    // when the recursion stops
    if (cur_node == nullptr) {
      return;
    }
    
    // the left child
    inorder_walker(cur_node->left, result);
    
    // the parent
    result.push_back(cur_node->val);
    
    // the right child
    inorder_walker(cur_node->right, result);
  }
 public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorder_walker(root, result);
    return result;
  }
};

/* Runtime: 3 ms, faster than 61.76% of C++ online submissions for Binary Tree Inorder Traversal.
 * Memory Usage: 8.4 MB, less than 39.71% of C++ online submissions for Binary Tree Inorder Traversal.
 */

