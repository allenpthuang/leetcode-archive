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
  void inorder_walker(TreeNode* cur_node, int& cur_sum) {
    if (cur_node == nullptr) {
      return;
    }
    inorder_walker(cur_node->right, cur_sum);
    cur_node->val += cur_sum;
    cur_sum = cur_node->val;
    inorder_walker(cur_node->left, cur_sum);
  }
 public:
  TreeNode* convertBST(TreeNode* root) {
    int cur_sum = 0;
    inorder_walker(root, cur_sum);
    return root;
  }
};

/* Runtime: 66 ms, faster than 6.27% of C++ online submissions for Convert BST to Greater Tree.
 * Memory Usage: 33.4 MB, less than 62.77% of C++ online submissions for Convert BST to Greater Tree.
 */

