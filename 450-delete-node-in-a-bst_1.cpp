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
  void worker(TreeNode* cur_node, int& key, vector<TreeNode*>& result) {
    if (cur_node == nullptr) {
      return;
    }
    worker(cur_node->left, key, result);
    if (cur_node->val != key) {
      result.push_back(cur_node);
    }
    worker(cur_node->right, key, result);
  }
 public:
  TreeNode* deleteNode(TreeNode* root, int key) {
    vector<TreeNode*> result;
    worker(root, key, result);
    TreeNode* dummy_head = new TreeNode();
    TreeNode* cur_node = dummy_head;
    for (auto& node : result) {
      node->left = nullptr;
      node->right = nullptr;
      cur_node->right = node;
      cur_node = cur_node->right;
    }
    return dummy_head->right;
  }
};

/* Runtime: 32 ms, faster than 92.89% of C++ online submissions for Delete Node in a BST.
 * Memory Usage: 21.5 MB, less than 100.00% of C++ online submissions for Delete Node in a BST.
 */

