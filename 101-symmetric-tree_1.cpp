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
  bool isSymmetric(TreeNode* root) {
    if (root->left == nullptr && root->right == nullptr) {
      return true;
    }
    
    queue<TreeNode*> lq;
    queue<TreeNode*> rq;
    lq.push(root->left);
    rq.push(root->right);
    while (! (lq.empty() || rq.empty())) {
      if (lq.size() != rq.size()) {
        return false;
      }
      int level_size = lq.size();
      vector<TreeNode*> cur_left_nodes;
      vector<TreeNode*> cur_right_nodes;
      while (level_size > 0) {
        TreeNode* cur_left = lq.front();
        TreeNode* cur_right = rq.front();
        lq.pop();
        rq.pop();
        cur_left_nodes.push_back(cur_left);
        cur_right_nodes.push_back(cur_right);
        if (cur_left != nullptr) {
          lq.push(cur_left->left);
          lq.push(cur_left->right);
        }
        if (cur_right != nullptr) {
          rq.push(cur_right->left);
          rq.push(cur_right->right);
        }
        level_size--;
      }

      int n = cur_left_nodes.size();
      for (int i = 0; i < n; i++) {
        TreeNode* lnode = cur_left_nodes[i];
        TreeNode* rnode = cur_right_nodes[n - i - 1];
        if (lnode != rnode) {
          if (lnode == nullptr || rnode == nullptr) {
            return false;
          } else {
            if (lnode->val != rnode->val) {
              return false;
            }
          }
        }
      }
    }
    if (lq.size() != rq.size()) {
      return false;
    }
    return true;
  }
};

/* Runtime: 4 ms, faster than 82.04% of C++ online submissions for Symmetric Tree.
 * Memory Usage: 17 MB, less than 7.60% of C++ online submissions for Symmetric Tree.
 */

