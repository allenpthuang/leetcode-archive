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
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    unordered_set<TreeNode*> visited;
    if (root == nullptr) return result;
    st.push(root);
    while (! st.empty()) {
      TreeNode* cur_node = st.top();
      if ((cur_node->right != nullptr) &&
          (visited.find(cur_node->right) == visited.end())) {
        st.pop();
        st.push(cur_node->right);
        visited.insert(cur_node->right);
        st.push(cur_node);
      }
      
      if ((cur_node->left != nullptr) &&
          (visited.find(cur_node->left) == visited.end())) {
        st.push(cur_node->left);
      } else {
        result.push_back(cur_node->val);
        visited.insert(cur_node);
        st.pop();
      }
    }
    return result;
  }
};

/* Runtime: 4 ms, faster than 44.23% of C++ online submissions for Binary Tree Inorder Traversal.
 * Memory Usage: 8.4 MB, less than 66.10% of C++ online submissions for Binary Tree Inorder Traversal.
 */

