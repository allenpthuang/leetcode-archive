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
  TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
      return root;
    }
    
    if (root->val == key) {
      if (root->left == nullptr && root->right == nullptr) {
        return nullptr;
      } else if (root->left == nullptr) {
        return root->right;
      } else if (root->right == nullptr) {
        return root->left;
      } else {
        TreeNode* new_spot = root->right;
        while (new_spot->left != nullptr) {
          new_spot = new_spot->left;
        }
        new_spot->left = root->left;
        return root->right;
      }
    }
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
  }
};

/* Runtime: 62 ms, faster than 16.92% of C++ online submissions for Delete Node in a BST.
 * Memory Usage: 32.7 MB, less than 77.01% of C++ online submissions for Delete Node in a BST.
 */

