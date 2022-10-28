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
  void worker(TreeNode* cur_node, TreeNode*& prev_node,
              int& cur_count, int& cur_max_count, vector<int>& result) {
    if (cur_node == nullptr) {
      return;
    }
    worker(cur_node->left, prev_node, cur_count, cur_max_count, result);
    if (prev_node == nullptr) {
      cur_count++;
      result.push_back(cur_node->val);
      cur_max_count = cur_count;
    } else if (prev_node->val == cur_node->val) {
      cur_count++;
      if (cur_max_count == cur_count) {
        result.push_back(cur_node->val);
      } else if (cur_max_count < cur_count) {
        result.clear();
        result.push_back(cur_node->val);
        cur_max_count = cur_count;
      }
    } else {
      cur_count = 1;
      if (cur_count == cur_max_count) {
        result.push_back(cur_node->val);
      }
    }
    prev_node = cur_node;
    worker(cur_node->right, prev_node, cur_count, cur_max_count, result);
  }

 public:
  vector<int> findMode(TreeNode* root) {
    TreeNode* prev_node = nullptr;
    int cur_count = 0;
    int cur_max_count = 0;
    vector<int> result;
    worker(root, prev_node, cur_count, cur_max_count, result);
    return result;
  }
};

/* Runtime: 26 ms, faster than 62.71% of C++ online submissions for Find Mode in Binary Search Tree.
 * Memory Usage: 24 MB, less than 91.71% of C++ online submissions for Find Mode in Binary Search Tree.
 */

