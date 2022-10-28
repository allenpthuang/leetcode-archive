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
  void inorder_walker(TreeNode* cur_node, vector<pair<int, TreeNode*> >& inorder_res) {
    if (cur_node == nullptr) {
      return;
    }
    
    inorder_walker(cur_node->left, inorder_res);
    inorder_res.push_back(pair<int, TreeNode*>(cur_node->val, cur_node));
    inorder_walker(cur_node->right, inorder_res);
  }
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    vector<pair<int, TreeNode*> > inorder_res;
    inorder_walker(root, inorder_res);
    pair<int, TreeNode*> p_ins = pair(val, new TreeNode(val));
    auto it = lower_bound(inorder_res.begin(), inorder_res.end(), p_ins);

    vector<pair<int, TreeNode*> > left(inorder_res.begin(), it);
    reverse(left.begin(), left.end());
    vector<pair<int, TreeNode*> > right(it, inorder_res.end());

    TreeNode* result = p_ins.second;
    TreeNode* cur_node = result;
    for (const auto& p : left) {
      cur_node->left = p.second;
      cur_node = cur_node->left;
      cur_node->left = nullptr;
      cur_node->right = nullptr;
    }
    cur_node = result;
    for (const auto& p : right) {
      cur_node->right = p.second;
      cur_node = cur_node->right;
      cur_node->left = nullptr;
      cur_node->right = nullptr;
    }
    
    return result;
  }
};

/* Runtime: 113 ms, faster than 52.97% of C++ online submissions for Insert into a Binary Search Tree.
 * Memory Usage: 34 MB, less than 99.98% of C++ online submissions for Insert into a Binary Search Tree.
 */

