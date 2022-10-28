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
  bool worker(TreeNode* cur_p, TreeNode* cur_q) {
    if (cur_p == nullptr && cur_q == nullptr) {
      return true;
    } else if (cur_p == nullptr || cur_q == nullptr) {
      return false;
    } else if (cur_p->val != cur_q->val) {
      return false;
    }

    bool left = worker(cur_p->left, cur_q->left);
    bool right = worker(cur_p->right, cur_q->right);
    return left && right;
  }

 public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    return worker(p, q);
  }
};

/* Runtime: 3 ms, faster than 63.47% of C++ online submissions for Same Tree.
 * Memory Usage: 9.9 MB, less than 78.32% of C++ online submissions for Same Tree.
 */

