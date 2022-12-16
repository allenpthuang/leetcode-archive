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
      if (cur_node->val > p->val && cur_node->val > q->val) { // LCA on the left
        cur_node = cur_node->left;
      } else if (cur_node->val < p->val && cur_node->val < q->val) { // LCA on the right
        cur_node = cur_node->right;
      } else {
        return cur_node;
      }
    }
    return cur_node;
  }
};

/**
 * Idea: because it is a BST, we can leverage the property of all LHS nodes
 * being samller than the cur_node, and all RHS nodes being larger.
 * If p->val and q->val are both less than cur_node->val, then there must
 * exist a node that can "sit between" p and q.
 */

