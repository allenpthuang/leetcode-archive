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
  vector<string> result;
  void worker(TreeNode* cur_node, string cur_str) {
    if (cur_node == nullptr) {
      return;
    }
    if (cur_node->left == nullptr && cur_node->right == nullptr) {
      cur_str += to_string(cur_node->val);
      result.push_back(cur_str);
      return;
    } else {
      cur_str += to_string(cur_node->val) + "->";
      worker(cur_node->left, cur_str);
      worker(cur_node->right, cur_str);
    }
  }
 public:
  vector<string> binaryTreePaths(TreeNode* root) {
    worker(root, "");
    return result;
  }
};

/* Runtime: 7 ms, faster than 48.09% of C++ online submissions for Binary Tree Paths.
 * Memory Usage: 13.3 MB, less than 29.07% of C++ online submissions for Binary Tree Paths.
 */

