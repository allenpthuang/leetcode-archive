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
  bool worker(TreeNode* cur_node, int cur_sum, int& targetSum) {
    if (cur_node == nullptr) {
      return false;
    }
    if (cur_node->left == nullptr && cur_node->right == nullptr) {
      cur_sum += cur_node->val;
      if (cur_sum == targetSum) {
        return true;
      } else {
        return false;
      }
    }
    cur_sum += cur_node->val;
    return worker(cur_node->left, cur_sum, targetSum)
      || worker(cur_node->right, cur_sum, targetSum);
  }

 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) {
      return false;
    }
    return worker(root, 0, targetSum);
  }
};

/* Runtime: 10 ms, faster than 82.45% of C++ online submissions for Path Sum.
 * Memory Usage: 21.4 MB, less than 40.76% of C++ online submissions for Path Sum.
 */

