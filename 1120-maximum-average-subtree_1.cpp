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
  pair<long long, int> dfs(TreeNode* cur_node,
                           TreeNode*& cur_max_head, double& cur_max_avg) {
    if (cur_node == nullptr) {
      return pair<long long, int>{0, 0};
    }
    pair<long long, int> left = dfs(cur_node->left, cur_max_head, cur_max_avg);
    pair<long long, int> right = dfs(cur_node->right, cur_max_head, cur_max_avg);
    long long cur_sum = cur_node->val + left.first + right.first;
    int cur_count = 1 + left.second + right.second;
    double cur_avg = cur_sum / double(cur_count);
    if (cur_avg > cur_max_avg) {
      cur_max_avg = cur_avg;
      cur_max_head = cur_node;
    }
    return pair<long long, int>{cur_sum, cur_count};
  }
  
 public:
  double maximumAverageSubtree(TreeNode* root) {
    // To calc a node's avg as a head of a substree:
    // (node->val + left_sum + right_sum) / (1 + left_count + right_count)
    // Use DFS. Pass the sums and node counts upwrads.
    // The base (leaf): left/right_sum/count = 0
    TreeNode* cur_max_head;
    double cur_max_avg = 0.0;
    TreeNode* dummy_head = new TreeNode(0);
    dummy_head->left = root;
    dfs(dummy_head, cur_max_head, cur_max_avg);
    
    return cur_max_avg;
  }
};

/* Runtime: 20 ms, faster than 69.35% of C++ online submissions for Maximum Average Subtree.
 * Memory Usage: 21.9 MB, less than 96.77% of C++ online submissions for Maximum Average Subtree.
 */

