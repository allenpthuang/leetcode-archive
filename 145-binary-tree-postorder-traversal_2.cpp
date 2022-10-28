// use a stack

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
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> st;
    unordered_set<TreeNode*> visited;
    if (root == nullptr) return result;
 
    st.push(root);
    while (! st.empty()) {
      TreeNode* cur_node = st.top();
      if ((cur_node->left == nullptr || visited.find(cur_node->left) != visited.end()) &&
          (cur_node->right == nullptr || visited.find(cur_node->right) != visited.end())) {
        result.push_back(cur_node->val);
        visited.insert(cur_node);
        st.pop();
        continue;
      }
      
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

/* Runtime: 7 ms, faster than 5.88% of C++ online submissions for Binary Tree Postorder Traversal.
 * Memory Usage: 8.3 MB, less than 96.06% of C++ online submissions for Binary Tree Postorder Traversal.
 */

