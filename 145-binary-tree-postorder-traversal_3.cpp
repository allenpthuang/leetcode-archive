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
  void postorder_walker(TreeNode* cur_node, vector<int>& result) {
    // when the recursion stops
    if (cur_node == nullptr) {
      return;
    }

    // first we process the left child
    postorder_walker(cur_node->left, result);
    
    // then the right child
    postorder_walker(cur_node->right, result);
    
    // and finally the cur_node (the parent)
    result.push_back(cur_node->val);
  }

 public:
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    postorder_walker(root, result);
    return result;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Postorder Traversal.
 * Memory Usage: 8.5 MB, less than 64.81% of C++ online submissions for Binary Tree Postorder Traversal.
 */

