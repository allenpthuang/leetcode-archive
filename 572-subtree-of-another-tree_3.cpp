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
  bool is_same(TreeNode* lhs, TreeNode* rhs) {
    if (lhs == nullptr && rhs == nullptr) return true;
    if (!(lhs != nullptr && rhs != nullptr)) return false;
    if (lhs->val != rhs->val) return false;
    return is_same(lhs->left, rhs->left) && is_same(lhs->right, rhs->right);
  }

 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) return false;
    if (is_same(root, subRoot)) return true;
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};

/**
 * Idea: kind of brute-force-ish, with the underlying concept similar to
 * Same Tree (LC 100).
 *
 * is_same(lhs, rhs): check this node, and if it's not valid (by several rules)
 * return false. If it's valid, do it on left and right children too and return
 * (left && right).
 *
 * isSubtree: check if cur_node and subRoot will return true in is_same().
 * If not, go for cur_node->left and cur_node->right.
 */

/* Runtime
15 ms
Beats
99.67%
Memory
28.7 MB
Beats
95.91%
*/

