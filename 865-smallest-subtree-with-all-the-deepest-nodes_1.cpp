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
  pair<int, TreeNode*> helper(TreeNode* cur_node) {
    // base case
    if (cur_node == nullptr) {
      return {0, cur_node};
    }

    // get left and right results
    auto [left_depth, left_subroot] = helper(cur_node->left);
    auto [right_depth, right_subroot] = helper(cur_node->right);

    if (left_depth == right_depth) { // case 1: same depth
      return {left_depth + 1, cur_node};
    } else if (left_depth > right_depth) { // case 2: uneven depth
      return {left_depth + 1, left_subroot};
    } else {
      return {right_depth + 1, right_subroot};
    }
  }

 public:
  TreeNode* subtreeWithAllDeepest(TreeNode* root) {
    auto [ignore, result] = helper(root);
    return result;
  }
};

/**
 * Idea (from Lee): solve this in a recursive way.
 * Write a function that goes to the left and right child,
 * and returns the depth it goes and the subroot of that
 * tree.
 *
 * Base case: leaf, left and right are nullptr, with depth = 0.
 * Case 1: left and right subtrees have the same depth.
 *         --> cur_depth = depth_l + 1; cur_subroot = cur_node
 * Case 2: one of them has a deeper depth.
 *         --> cur_depth = depth_deeper + 1; cur_subroot = left or right
 */

/* Runtime
0 ms
Beats
100%
Memory
14.5 MB
Beats
30.42%
*/

