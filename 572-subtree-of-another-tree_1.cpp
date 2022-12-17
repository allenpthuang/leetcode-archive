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
  TreeNode* find_node_matches(TreeNode* cur_node, TreeNode* subRoot) {
    if (cur_node == nullptr) {
      return nullptr;
    }
    TreeNode* result;
    result = find_node_matches(cur_node->left, subRoot);
    if (result != nullptr) return result;
    if (cur_node->val == subRoot->val) return cur_node;
    result = find_node_matches(cur_node->right, subRoot);
    return result;
  }

  bool walk_together(TreeNode* lhs_node, TreeNode* rhs_node, TreeNode*& start) {
    if (lhs_node == nullptr && rhs_node == nullptr) {
      return true;
    }
    if (!(lhs_node != nullptr && rhs_node != nullptr)) {
      start = lhs_node;
      return false;
    }
    bool result;
    result = walk_together(lhs_node->left, rhs_node->left, start);
    if (!result) {
      start = lhs_node;
      return false;
    }
    if (lhs_node->val != rhs_node->val) {
      start = lhs_node;
      return false;
    }
    result = walk_together(lhs_node->right, rhs_node->right, start);
    return result;
  }

 public:
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    TreeNode* start = nullptr;
    TreeNode* cur_start_node = root;
    while ((cur_start_node = find_node_matches(cur_start_node, subRoot))) {
      if (walk_together(cur_start_node, subRoot, start)) {
        return true;
      } else {
        cur_start_node = start;
      }
    }
    return false;
  }
};

/**
 * Idea: do in-order traversal, and when cur_node == subRoot,
 * continue to walk together to check if every node along the
 * way matches. If not, go to next cur_node == subRoot until
 * cur_node == nullptr (no chance).
 */

/* TLE; looooooop */

