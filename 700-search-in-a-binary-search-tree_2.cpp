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
  TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) {
      return root;
    } else if (root->val > val) {
      return searchBST(root->left, val);
    } else {
      return searchBST(root->right, val);
    }
  }
};

/* Runtime: 63 ms, faster than 8.07% of C++ online submissions for Search in a Binary Search Tree.
 * Memory Usage: 34.6 MB, less than 99.81% of C++ online submissions for Search in a Binary Search Tree.
 */

