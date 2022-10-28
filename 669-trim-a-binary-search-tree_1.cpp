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
  TreeNode* trimBST(TreeNode* root, int low, int high) {
    if (root == nullptr) {
      return root;
    }
    
    if (root->val < low) {
      return trimBST(root->right, low, high);
    } else if (root->val > high) {
      return trimBST(root->left, low, high);
    }
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
  }
};

/* Runtime: 42 ms, faster than 6.60% of C++ online submissions for Trim a Binary Search Tree.
 * Memory Usage: 23.9 MB, less than 52.11% of C++ online submissions for Trim a Binary Search Tree.
 */

