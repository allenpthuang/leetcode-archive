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
  void walker(TreeNode* cur_node, TreeNode*& prev_node,
              vector<TreeNode*>& anomalies) {
    if (cur_node == nullptr) return;
    walker(cur_node->left, prev_node, anomalies);
    if (prev_node != nullptr && prev_node->val >= cur_node->val) {
      // cout << prev_node->val << " >= " << cur_node->val << endl;
      if (anomalies[0] == nullptr) {
        anomalies[0] = prev_node;
      }
      if (anomalies[0] != nullptr) {
        anomalies[1] = cur_node;
      }
    }
    // cout << cur_node->val << endl;
    prev_node = cur_node;
    walker(cur_node->right, prev_node, anomalies);
  }

 public:
  void recoverTree(TreeNode* root) {
    vector<TreeNode*> anomalies(2, nullptr);
    TreeNode* prev_node = nullptr;
    walker(root, prev_node, anomalies);
    // cout << anomalies.size() << endl;
    swap(anomalies[0]->val, anomalies[1]->val);
  }
};

/**
 * Idea: do in-order traversal, and log it down if there is
 * an anomaly (normal: prev < cur).
 */

