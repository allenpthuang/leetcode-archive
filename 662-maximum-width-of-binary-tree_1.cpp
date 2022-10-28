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
  int widthOfBinaryTree(TreeNode* root) {
    vector<TreeNode*> bfs;
    TreeNode* dummy_null = new TreeNode(-5566);
    
    bfs.push_back(root);
    for (int i = 0; i < bfs.size(); i++) {
      TreeNode* cur_node = bfs[i];
      if (cur_node == nullptr) {
        cur_node = dummy_null;
      }
      bfs.push_back(cur_node->left);
      bfs.push_back(cur_node->right);
      /*
      if (cur_node != nullptr) {
        bfs.push_back(cur_node->left);
        bfs.push_back(cur_node->right);
      } else {
        cur_node = dummy_null;
      }
      */
    }
    
    int cur_max = INT_MIN;
    int height = 0;
    int cur_level_start = 0;
    int left_idx = -1;
    int right_idx = -1;
    bool found_left = false;
    for (int i = 0; i < bfs.size(); i++) {
      TreeNode* cur_node = bfs[i];
      if (cur_node != nullptr && cur_node->val != -5566) {
        if (! found_left) {
          left_idx = i;
          found_left = true;
        } else {
          right_idx = i;
        }
      }
      
      if (i == cur_level_start + pow(2, height) - 1) {
        cur_max = max(cur_max, right_idx - left_idx + 1);
        cur_level_start = i + 1;
        height++;
        left_idx = -1;
        right_idx = -1;
        found_left = false;
      }
    }
    
    return cur_max;
  }
};

/* wrong, infinite dummy_null nodes */

