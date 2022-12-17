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
  void traverse(TreeNode* cur_node, vector<int>& values) {
    if (cur_node == nullptr) return;
    traverse(cur_node->left, values);
    values.push_back(cur_node->val);
    traverse(cur_node->right, values);
  }

  int sum_up(vector<int>& values, int low, int high) {
    auto it_low = lower_bound(values.begin(), values.end(), low);
    auto it_high = upper_bound(values.begin(), values.end(), high);
    int sum = 0;
    while (it_low != it_high) {
        sum += *it_low;
        it_low++;
    }
    return sum;
  }

 public:
  int rangeSumBST(TreeNode* root, int low, int high) {
    vector<int> values;
    traverse(root, values);
    return sum_up(values, low, high);
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
131 ms
Beats
94.21%
Memory
67.3 MB
Beats
5.45%
*/

