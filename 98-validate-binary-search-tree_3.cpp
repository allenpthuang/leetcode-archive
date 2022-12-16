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
  bool traverse(TreeNode* cur_node, int& prev_val) {
    if (cur_node == nullptr) {
      return true;
    }
    
    bool left = traverse(cur_node->left, prev_val);
    if (cur_node->val <= prev_val) {
      return false;
    }
    prev_val = cur_node->val;
    bool right = traverse(cur_node->right, prev_val);
    return left && right;
  }
 public:
  bool isValidBST(TreeNode* root) {
    int prev_val = INT_MIN;
    return traverse(root, prev_val);
  }
};

/* Wrong answer: root = [-2147483648] */

