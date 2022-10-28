/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
 public:
  int maxDepth(Node* root) {
    if (root == nullptr) {
      return 0;
    }
    queue<Node*> q;
    q.push(root);
    int max_depth = 0;

    while (! q.empty()) {
      int level_size = q.size();
      max_depth++;
      while (level_size > 0) {
        Node* cur_node = q.front();
        q.pop();
        if (cur_node != nullptr) {
          for (const auto& child : cur_node->children) {
            q.push(child);
          }
        }
        level_size--;
      }
    }
    return max_depth;
  }
};

/* Runtime: 23 ms, faster than 39.83% of C++ online submissions for Maximum Depth of N-ary Tree.
 * Memory Usage: 11 MB, less than 15.15% of C++ online submissions for Maximum Depth of N-ary Tree.
 */

