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
  void worker(TreeNode*& cur_node, vector<int> in, vector<int> post) {
    if (post.size() == 0) {
      return;
    }
    if (cur_node == nullptr) {
      cur_node = new TreeNode();
    }
    int cur_val = post[post.size() - 1];
    post.pop_back();
    
    cur_node->val = cur_val;
    
    auto it = find(in.begin(), in.end(), cur_val);
    int left_len = distance(in.begin(), it);
    vector<int> left_in(in.begin(), in.begin() + left_len);
    vector<int> right_in(in.begin() + left_len + 1, in.end());
    vector<int> left_post(post.begin(), post.begin() + left_in.size());
    vector<int> right_post(post.begin() + left_in.size(), post.end());
    worker(cur_node->left, left_in, left_post);
    worker(cur_node->right, right_in, right_post);
  }
 public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    TreeNode* root = new TreeNode();
    worker(root, inorder, postorder);
    return root;
  }
};

/* Runtime: 71 ms, faster than 12.09% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
 * Memory Usage: 121.2 MB, less than 8.30% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
 */

