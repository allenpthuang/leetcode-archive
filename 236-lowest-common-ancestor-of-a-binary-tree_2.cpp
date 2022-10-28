/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 private:
  TreeNode* worker(TreeNode* cur_node, TreeNode*& p, TreeNode*& q) {
    if (cur_node == nullptr || cur_node == p || cur_node == q) {
      return cur_node;
    }

    TreeNode* left = worker(cur_node->left, p, q);
    TreeNode* right = worker(cur_node->right, p, q);
    if (left == nullptr && right == nullptr) {
      return nullptr;
    } else if (left != nullptr && right != nullptr) {
      return cur_node;
    } else if (left == nullptr) {
      return right;
    } else {
      return left;
    }
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return worker(root, p, q);
  }
};

/* Runtime: 24 ms, faster than 40.53% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
 * Memory Usage: 14.1 MB, less than 97.18% of C++ online submissions for Lowest Common Ancestor of a Binary Tree.
 */

