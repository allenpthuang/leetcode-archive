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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p != nullptr && q != nullptr && p->val != q->val) {
      return false;
    } else if (p == nullptr || q == nullptr) {
      return false;
    }
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
    return left && right;
  }
};

/**
 * Idea: traverse the two trees at the same time;
 * when one of them is nullptr but the other is not
 * OR p->val != q->val 
 */

