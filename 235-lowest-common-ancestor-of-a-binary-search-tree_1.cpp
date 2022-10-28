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
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* cur_node = root;
    while (cur_node != nullptr) {
      if (cur_node->val > p->val && cur_node->val > q->val) {
        cur_node = cur_node->left;
      } else if (cur_node->val < p->val && cur_node->val < q->val) {
        cur_node = cur_node->right;
      } else {
        return cur_node;
      }
    }
    
    return nullptr;
  }
};

/* Runtime: 54 ms, faster than 14.88% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
 * Memory Usage: 23.3 MB, less than 13.51% of C++ online submissions for Lowest Common Ancestor of a Binary Search Tree.
 */

