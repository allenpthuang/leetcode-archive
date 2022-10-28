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
  void lv_sum_helper(TreeNode* cur_head, int level, vector<int>& sum_of_lv) {
    if (cur_head == nullptr) return;

    if (sum_of_lv.size() <= level) {
      sum_of_lv.push_back(0);
    }
    
    sum_of_lv[level] += cur_head->val;
    lv_sum_helper(cur_head->left, level + 1, sum_of_lv);
    lv_sum_helper(cur_head->right, level + 1, sum_of_lv);
  }

  int rob(TreeNode* root) {
    int level = 0;
    vector<int> sum_of_lv;
    lv_sum_helper(root, level, sum_of_lv);
    
    // dp[i]: the max rob value at the i-th level
    vector<int> dp(sum_of_lv.size(), 0);
    
    // walk thru
    if (sum_of_lv.size() == 0) return 0;
    if (sum_of_lv.size() == 1) return sum_of_lv[0];
    dp[0] = sum_of_lv[0];
    dp[1] = max(sum_of_lv[0], sum_of_lv[1]);
    for (int i = 2; i < sum_of_lv.size(); i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + sum_of_lv[i]);
    }
    
    return dp[sum_of_lv.size() - 1];
  }
};

/* Because the theif could rob in different patterns in the left or right trees! */

