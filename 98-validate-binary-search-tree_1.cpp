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
  void in_order_walker(TreeNode* cur_node, vector<int>& output) {
    if (cur_node == nullptr) return;
    in_order_walker(cur_node->left, output);
    output.push_back(cur_node->val);
    in_order_walker(cur_node->right, output);
  }
  bool isValidBST(TreeNode* root) {
    vector<int> output;
    in_order_walker(root, output);
    for (int i = 1; i < output.size(); i++) {
      if (output[i] <= output[i-1]) {
        return false;
      }
    }
    return true;
  }
};

/* Runtime: 19 ms, faster than 46.16% of C++ online submissions for Validate Binary Search Tree.
 * Memory Usage: 21.8 MB, less than 16.06% of C++ online submissions for Validate Binary Search Tree.
 */

