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
  void rob_helper(TreeNode* root, int level, int& cnt1, int& cnt2) {
    if (level % 2 != 0) {
      cnt1 += root->val;
    } else {
      cnt2 += root->val;
    }
    
    if (root->left != nullptr) {
      rob_helper(root->left, level + 1, cnt1, cnt2);
    }
    
    if (root->right != nullptr) {
      rob_helper(root->right, level + 1, cnt1, cnt2);
    }
    
    if (root->left == nullptr || root->right == nullptr) return;
  }

  int rob(TreeNode* root) {
    int level = 1;
    int cnt1 = 0;
    int cnt2 = 0;
    
    rob_helper(root, level, cnt1, cnt2);
    return max(cnt1, cnt2);
  }
};

