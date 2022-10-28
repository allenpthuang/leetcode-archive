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
  void inorder_walker(TreeNode* cur_node, map<int, multimap<int, int> >& bins, int cur_offset, int level) {
    if (cur_node == nullptr) {
      return;
    }
    bins[cur_offset].insert(pair<int, int>{level, cur_node->val});
    inorder_walker(cur_node->left, bins, cur_offset - 1, level + 1);
    inorder_walker(cur_node->right, bins, cur_offset + 1, level + 1);
  }

 public:
  vector<vector<int>> verticalOrder(TreeNode* root) {
    // 1. Store values in "bins" by some offsets.
    //    cur_node will be using bins[cur_offset] (root->val will be in bins[0])
    //    and its left child will use bins[cur_offest - 1], and the right child
    //    using bins[cur_offset + 1].
    // 2. Pass the offset to the next level of recursion.
    // 3. From up to down so pre-order traversal is used.
    
    // use an ordered map for easier sorting
    map<int, multimap<int, int> > bins;  // offset -> level -> node value
    inorder_walker(root, bins, 0, 0);
    
    vector<vector<int> > result;
    for (const auto& bin : bins) {
      vector<int> bin_vec;
      for (const auto& elem : bin.second) {
        bin_vec.push_back(elem.second);
      }
      result.push_back(bin_vec);
    }
    return result;
  }
};

/* Runtime: 8 ms, faster than 53.00% of C++ online submissions for Binary Tree Vertical Order Traversal.
 * Memory Usage: 13 MB, less than 16.08% of C++ online submissions for Binary Tree Vertical Order Traversal.
 */

