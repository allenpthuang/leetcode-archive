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
  vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > result;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    vector<int> tmp;
    int level_size = q.size();
    while (! q.empty()) {
      if (level_size == 0) {
        level_size = q.size();
        level++;
        result.push_back(tmp);
        tmp.clear();
      }

      TreeNode* cur_node = q.front();
      q.pop();
      level_size--;
      if (cur_node != nullptr) {
        tmp.push_back(cur_node->val);
        q.push(cur_node->left);
        q.push(cur_node->right);
      }
    }
    return result;
  }
};

/*Runtime: 3 ms, faster than 84.89% of C++ online submissions for Binary Tree Level Order Traversal.
 * Memory Usage: 12.5 MB, less than 61.79% of C++ online submissions for Binary Tree Level Order Traversal.
 */

