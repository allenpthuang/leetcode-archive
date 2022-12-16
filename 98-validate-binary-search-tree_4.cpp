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
  bool traverse(TreeNode* cur_node, TreeNode*& prev_node) {
    if (cur_node == nullptr) {
      return true;
    }
    
    bool left = traverse(cur_node->left, prev_node);
    if (prev_node != nullptr && cur_node->val <= prev_node->val) {
      return false;
    }
    prev_node = cur_node;
    bool right = traverse(cur_node->right, prev_node);
    return left && right;
  }
 public:
  bool isValidBST(TreeNode* root) {
    TreeNode* prev_node = nullptr;
    return traverse(root, prev_node);
  }
};

