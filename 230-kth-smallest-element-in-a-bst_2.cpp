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
  void inorder_walker(TreeNode* cur_node, int& cur_step, int k, int& result) {
    if (cur_node == nullptr) {
      return;
    }
    inorder_walker(cur_node->left, cur_step, k, result);
    cur_step++;
    if (cur_step == k) {
      result = cur_node->val;
      return;
    }
    inorder_walker(cur_node->right, cur_step, k, result);
  }

 public:
  int kthSmallest(TreeNode* root, int k) {
    int cur_step = 0;
    int result = 0;
    inorder_walker(root, cur_step, k, result);
    return result;
  }
};

/* Runtime
11 ms
Beats
99.37%
Memory
24.2 MB
Beats
61.96%
*/

/*
 * In-order traversal of a BST yields a ascending sequence.
 * Example 1 yields [1, 2, 3, 4]
 * Idea: use a traversal walker and stop at a given step.
 */
