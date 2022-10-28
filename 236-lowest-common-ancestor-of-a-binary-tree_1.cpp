/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 private:
  void post_walker(TreeNode* cur_node, vector<TreeNode*>& result) {
    if (cur_node == nullptr) {
      return;
    }
    post_walker(cur_node->left, result);
    post_walker(cur_node->right, result);
    result.push_back(cur_node);
  }
  
  void in_walker(TreeNode* cur_node, vector<TreeNode*>& result) {
    if (cur_node == nullptr) {
      return;
    }
    in_walker(cur_node->left, result);
    result.push_back(cur_node);
    in_walker(cur_node->right, result);
  }

 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    vector<TreeNode*> post_res;
    vector<TreeNode*> in_res;
    post_walker(root, post_res);
    in_walker(root, in_res);
    
    int n = post_res.size();
    for (int i = n - 1; i >= 0; i--) {
      int idx_p = 0;
      int idx_q = 0;
      int idx_mid = 0;
      for (int j = 0; j < n; j++) {
        if (in_res[j] == p) {
          idx_p = j;
        } else if (in_res[j] == q) {
          idx_q = j;
        } else if (in_res[j] == post_res[i]) {
          idx_mid = j;
        }
      }
      if (idx_p < idx_q) {
        if (idx_p < idx_mid && idx_mid < idx_q) {
          return post_res[i];
        }
      } else {
        if (idx_q < idx_mid && idx_mid < idx_p) {
          return post_res[i];
        }
      }
    }
    
    return nullptr;
  }
};

/* wrong answer */

