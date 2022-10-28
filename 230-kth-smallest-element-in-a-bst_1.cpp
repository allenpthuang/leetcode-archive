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
  stack<TreeNode*> st;

 public:
  int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    TreeNode* cur_node = root;
    while (cur_node != nullptr || ! st.empty()) {
      while (cur_node != nullptr) {
        st.push(cur_node);
        cur_node = cur_node->left;
      }
      count++;
      if (count == k) {
        return st.top()->val;
      }
      cur_node = st.top()->right;
      st.pop();
    }
    return -1;
  }
};

/* Runtime: 43 ms, faster than 20.35% of C++ online submissions for Kth Smallest Element in a BST.
 * Memory Usage: 24.1 MB, less than 86.35% of C++ online submissions for Kth Smallest Element in a BST.
 */

