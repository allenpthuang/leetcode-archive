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
  void inorder_walker(TreeNode* cur_node, vector<TreeNode*>& inorder_res,
                     const int& val, bool& inserted) {
    if (cur_node == nullptr) {
      return;
    }
    
    inorder_walker(cur_node->left, inorder_res, val, inserted);
    if (! inserted && cur_node->val > val) {
      inorder_res.push_back(new TreeNode(val));
      inserted = true;
    }
    inorder_res.push_back(cur_node);
    inorder_walker(cur_node->right, inorder_res, val, inserted);
  }
 public:
  TreeNode* insertIntoBST(TreeNode* root, int val) {
    vector<TreeNode*> inorder_res;
    bool inserted = false;
    inorder_walker(root, inorder_res, val, inserted);
    TreeNode* dummy_head = new TreeNode();
    TreeNode* cur_node = dummy_head;
    for (auto& node : inorder_res) {
      node->left = nullptr;
      node->right = nullptr;
      cur_node->right = node;
      cur_node = cur_node->right;
    }
    if (! inserted) {
      cur_node->right = new TreeNode(val);
    }
    return dummy_head->right;
  }
};

/* Runtime: 92 ms, faster than 90.20% of C++ online submissions for Insert into a Binary Search Tree.
 * Memory Usage: 31.5 MB, less than 100.00% of C++ online submissions for Insert into a Binary Search Tree.
 */

