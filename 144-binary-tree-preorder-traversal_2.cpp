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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    if (root == nullptr) return result;
    st.push(root);
    while (! st.empty()) {
      TreeNode* cur_node = st.top();
      st.pop();
      result.push_back(cur_node->val);
      // push the right child first so that it could be popped after the left
      if (cur_node->right != nullptr) {
        st.push(cur_node->right);
      }
      if (cur_node->left != nullptr) {
        st.push(cur_node->left);
      }
    }
    return result;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Preorder Traversal.
 * Memory Usage: 8.3 MB, less than 94.09% of C++ online submissions for Binary Tree Preorder Traversal.
 */

