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
  void worker(TreeNode* cur_node, TreeNode* prev_node,
              int cur_depth, int& result, int& cur_res_depth) {
    if (cur_node == nullptr) {
      return;
    }
    if ((cur_node->left == nullptr && cur_node->right == nullptr)
         && prev_node->left == cur_node
         && cur_depth > cur_res_depth) {
      result = cur_node->val;
      cur_res_depth = cur_depth;
    } else {
      worker(cur_node->left, cur_node, cur_depth + 1, result, cur_res_depth);
      worker(cur_node->right, cur_node, cur_depth + 1, result, cur_res_depth);
    }
  }

 public:
  int findBottomLeftValue(TreeNode* root) {
    int result;
    int cur_res_depth = 0;
    TreeNode* dummy_head = new TreeNode();
    dummy_head->left = root;
    worker(root, dummy_head, 1, result, cur_res_depth);
    return result;
  }
};

/* wrong answer */

