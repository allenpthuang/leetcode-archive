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
  void worker(TreeNode* cur_node, TreeNode* prev_node, int& result) {
    if (cur_node == nullptr) {
      return;
    }
    
    if (cur_node->left == nullptr && cur_node->right == nullptr) {
      if (prev_node->left == cur_node) {
        result += cur_node->val;
      }
    } else {
      worker(cur_node->left, cur_node, result);
      worker(cur_node->right, cur_node, result);
    }
  }

 public:
  int sumOfLeftLeaves(TreeNode* root) {
    int result = 0;
    TreeNode* dummy_head = new TreeNode();
    dummy_head->right = root;
    worker(root, dummy_head, result);
    return result;
  }
};

/* Runtime: 9 ms, faster than 19.80% of C++ online submissions for Sum of Left Leaves.
 * Memory Usage: 13.5 MB, less than 46.02% of C++ online submissions for Sum of Left Leaves.
 */

