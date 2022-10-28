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
 public:
  void in_order_walker(TreeNode* cur_node, unordered_map<int, int>& val_map) {
    if (cur_node == nullptr) return;
    in_order_walker(cur_node->left, val_map);
    val_map[cur_node->val]++;
    in_order_walker(cur_node->right, val_map);
  }

  vector<int> findMode(TreeNode* root) {
    unordered_map<int, int> val_map;
    in_order_walker(root, val_map);
    
    int cur_max = INT_MIN;
    vector<int> result;
    for (const auto& m : val_map) {
      if (m.second > cur_max) {
        cur_max = m.second;
        vector<int> tmp;
        tmp.push_back(m.first);
        result = tmp;
      } else if (m.second == cur_max) {
        result.push_back(m.first);
      }
    }
    return result;
  }
};

/* Runtime: 43 ms, faster than 20.46% of C++ online submissions for Find Mode in Binary Search Tree.
 * Memory Usage: 25.4 MB, less than 43.73% of C++ online submissions for Find Mode in Binary Search Tree.
 */

