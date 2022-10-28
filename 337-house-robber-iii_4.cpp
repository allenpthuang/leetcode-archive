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
  // return a vecor
  // v[0] = the max when cur_head is robbed
  // v[1] = the max when cur_head is not robbed
  vector<int> rob_helper(TreeNode* cur_head) {
    if (cur_head == nullptr) return vector<int> {0, 0};
    vector<int> left = rob_helper(cur_head->left);
    vector<int> right = rob_helper(cur_head->right);
    
    int rob_this = left[1] + right[1] + cur_head->val;
    int not_rob_this = max(left[0], left[1]) + max(right[0], right[1]);
    return vector<int> {rob_this, not_rob_this};
  }
  
  int rob(TreeNode* root) {
    vector<int> result = rob_helper(root);
    return max(result[0], result[1]);
  }
};

/* Runtime: 36 ms, faster than 7.03% of C++ online submissions for House Robber III.
 * Memory Usage: 31.9 MB, less than 6.15% of C++ online submissions for House Robber III.
 */

