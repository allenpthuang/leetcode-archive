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
  TreeNode* worker(TreeNode* cur_node, int left, int right, vector<int>& nums) {
    if (left > right) {
      return nullptr;
    }
    int mid = (right - left) / 2 + left;
    cur_node = new TreeNode(nums[mid]);
    cur_node->left = worker(cur_node->left, left, mid - 1, nums);
    cur_node->right = worker(cur_node->right, mid + 1, right, nums);
    return cur_node;
  }
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return worker(new TreeNode(), 0, nums.size() - 1, nums);
  }
};

/* Runtime: 19 ms, faster than 59.39% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
 * Memory Usage: 21.4 MB, less than 78.53% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
 */

