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
  stack<TreeNode*>* working;
  stack<TreeNode*>* output;

 public:
  Solution() {
    working = new stack<TreeNode*>;
    output = new stack<TreeNode*>;
  }
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int> > results;
    vector<int> level_results;
    int level_cnt = 0;
    if (root != nullptr) {
      output->push(root);
    }
    while (! output->empty()) {
      TreeNode* cur_node = output->top();
      output->pop();
      level_results.push_back(cur_node->val);
      if (level_cnt % 2 != 0) {
        if (cur_node->right != nullptr) {
          working->push(cur_node->right);
        }
        if (cur_node->left != nullptr) {
          working->push(cur_node->left);
        }
      } else {
        if (cur_node->left != nullptr) {
          working->push(cur_node->left);
        }
        if (cur_node->right != nullptr) {
          working->push(cur_node->right);
        }
      }
      if (output->empty()) {
        swap(output, working);
        results.push_back(level_results);
        level_results.clear();
        level_cnt++;
      }
    }
    return results;
  }
};

/* Runtime: 5 ms, faster than 51.39% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
 * Memory Usage: 12.2 MB, less than 42.81% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
 */

