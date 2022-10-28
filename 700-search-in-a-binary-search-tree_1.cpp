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
  TreeNode* worker(TreeNode* cur_node, int& val) {
    if (cur_node->val == val) {
      return cur_node;
    } else if (cur_node->val > val) {
      if (cur_node->left != nullptr) {
        return worker(cur_node->left, val);
      } else {
        return nullptr;
      }
    } else {
      if (cur_node->right != nullptr) {
        return worker(cur_node->right, val);
      } else {
        return nullptr;
      }
    }
  }
 public:
  TreeNode* searchBST(TreeNode* root, int val) {
    return worker(root, val);
  }
};

/* Runtime: 54 ms, faster than 20.08% of C++ online submissions for Search in a Binary Search Tree.
 * Memory Usage: 34.6 MB, less than 94.04% of C++ online submissions for Search in a Binary Search Tree.
 */

