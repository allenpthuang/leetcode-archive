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
  TreeNode* find_subtree(TreeNode* cur_node, int low, int high) {
    if (cur_node->val > low && cur_node->val > high) {
      return find_subtree(cur_node->left, low, high);
    } else if (cur_node->val < low && cur_node->val < high) {
      return find_subtree(cur_node->right, low, high);
    } else {
      return cur_node;
    }
  }

  void traverse(TreeNode* cur_node, int low, int high, int& sum) {
    if (cur_node == nullptr) return;
    traverse(cur_node->left, low, high, sum);
    if (cur_node->val >= low && cur_node->val <= high) sum += cur_node->val;
    if (cur_node->val > high) return;
    traverse(cur_node->right, low, high, sum);
  }

 public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    TreeNode* sub_root = find_subtree(root, low, high);
    traverse(sub_root, low, high, sum);
    return sum;
  }
};

/**
 * Idea: it is a BST; hence, in-order traversal will yield a sorted sequence.
 * A naive way to do is storing all elements in a vector, and sum those
 * in range up.
 *
 * Some possible optimizations:
 *   - the values we want to sum up are actually in a subtree, with the subroot
 *     value sitting between low and high.
 *   - probably we can search "where to start/stop"?
 */

/* Runtime
126 ms
Beats
97%
Memory
64.7 MB
Beats
63.80%
*/

