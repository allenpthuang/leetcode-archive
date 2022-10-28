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
  TreeNode* worker(vector<int> nums) {
    if (nums.size() == 0) {
      return nullptr;
    }
    TreeNode* root = new TreeNode();
    int cur_max = INT_MIN;
    int max_idx = -1;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] > cur_max) {
        cur_max = nums[i];
        max_idx = i;
      }
    }
    root->val = cur_max;
    vector<int> left(nums.begin(), nums.begin() + max_idx);
    vector<int> right(nums.begin() + max_idx + 1, nums.end());
    root->left = worker(left);
    root->right = worker(right);
    return root;
  }
 public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return worker(nums);
  }
};

/* Runtime: 182 ms, faster than 17.67% of C++ online submissions for Maximum Binary Tree.
 * Memory Usage: 64 MB, less than 12.90% of C++ online submissions for Maximum Binary Tree.
 */

