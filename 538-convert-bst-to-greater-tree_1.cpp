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
  int get_sum(TreeNode* cur_node) {
    if (cur_node == nullptr) {
      return 0;
    }
    return cur_node->val + get_sum(cur_node->left) + get_sum(cur_node->right);
  }
  
  void inorder_walker(TreeNode* cur_node, int& rem) {
    if (cur_node == nullptr) {
      return;
    }
    inorder_walker(cur_node->left, rem);
    int cur_val = cur_node->val;
    cur_node->val = rem;
    rem -= cur_val;
    inorder_walker(cur_node->right, rem);
  }
 public:
  TreeNode* convertBST(TreeNode* root) {
    int sum = get_sum(root);
    inorder_walker(root, sum);
    return root;
  }
};

/* Runtime: 55 ms, faster than 15.08% of C++ online submissions for Convert BST to Greater Tree.
 * Memory Usage: 33.5 MB, less than 62.77% of C++ online submissions for Convert BST to Greater Tree.
 */

