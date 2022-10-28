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
  int lh = 0;
  int rh = 0;
  bool worker(TreeNode* cur_node) {
    if (cur_node == nullptr) return true;
    if (cur_node->left == nullptr && cur_node->right != nullptr) {
      return false;
    }
    bool l = worker(cur_node->left);
    bool r = worker(cur_node->right);
    return l && r;
  }

  bool isCompleteTree(TreeNode* root) {
    /*
    if (root == nullptr) return true;
    if (root->left == nullptr && root->right != nullptr) return false;
    bool l = worker(root->left, lh);
    bool r = worker(root->right, rh);
    
    cout << lh << " " << rh << endl;
    
    return (l && r); // && (lh == rh);
    */
    return worker(root);
  }
};

/* wrong answer */

