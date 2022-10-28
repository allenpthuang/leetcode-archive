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
  void rob_helper_2(TreeNode* root, int level, int& cnt1, int& cnt2) {
    if (level % 2 != 0) {
      cnt1 += root->val;
    } else {
      cnt2 += root->val;
    }
    
    if (root->left != nullptr) {
      rob_helper(root->left, level + 1, cnt1, cnt2);
    }
    
    if (root->right != nullptr) {
      rob_helper(root->right, level + 1, cnt1, cnt2);
    }
    
    if (root->left == nullptr || root->right == nullptr) return;
  }
  
  void rob_helper(TreeNode* cur_head, int level, vector<int>& dp) {
    dp[level] += cur_head->val;
    if (cur_head->left != nullptr) {
      rob_helper(cur_head->left, level + 1, dp);
    }
    while (cur_head->left != nullptr || cur_head->right != nullptr) {
      
    }
  }
  
  int rob_next_level(TreeNode* cur_head) {
    
  }

  int rob(TreeNode* root) {
    /*
    int level = 1;
    int cnt1 = 0;
    int cnt2 = 0;
    
    rob_helper(root, level, cnt1, cnt2);
    return max(cnt1, cnt2);
    */
    
    // dp[i]: the max rob value at the i-th level
    vector<int> dp (15, 0);
    
    // walk thru
    TreeNode* cur_head = root;
    dp[0] = cur_head->val;
    dp[1] = rob_next_level(cur_head);
    int level = 1;
    //if (cur_head->left != nullptr || cur_head )
    while (true) {
      if (cur_head->left != nullptr || cur_head->right != nullptr) {
        dp[level + 1] = max(dp[level], dp[level - 1] + rob_next_level(cur_head));
        level++;
      } else {
        break;
      }
    }
  }
};

