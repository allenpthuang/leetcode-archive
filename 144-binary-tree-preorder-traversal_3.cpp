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
  void preorder_walker(TreeNode* cur_node, vector<int>& result) {
    // when the recursion stops
    if (cur_node == nullptr) {
      return;
    }
    
    // deal with the parent (middle) node first
    result.push_back(cur_node->val);
    
    // and then the left child
    preorder_walker(cur_node->left, result);
    
    // and finally the right child
    preorder_walker(cur_node->right, result);
  }
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorder_walker(root, result);
    
    return result;
  }
};

/* Runtime: 3 ms, faster than 60.84% of C++ online submissions for Binary Tree Preorder Traversal.
 * Memory Usage: 8.4 MB, less than 76.77% of C++ online submissions for Binary Tree Preorder Traversal.
 */

