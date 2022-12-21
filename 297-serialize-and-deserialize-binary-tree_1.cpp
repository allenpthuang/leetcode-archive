/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string result = "";
    queue<TreeNode*> q;
    q.push(root);
    while (! q.empty()) {
      auto walk_size = q.size();
      while (walk_size--) {
        TreeNode* cur_node = q.front();
        q.pop();
        if (cur_node == nullptr) {
          result += "null ";
        } else {
          result += to_string(cur_node->val) + " ";
          q.push(cur_node->left);
          q.push(cur_node->right);
        }
      }
    }
    // cout << result << endl;
    return result;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    stringstream ss(data);
    string token = "";
    ss >> token;
    if (token == "null") return nullptr;
    TreeNode* head = new TreeNode(stoi(token));

    queue<TreeNode*> q;
    q.push(head);
    while (! q.empty()) {
      auto walk_size = q.size();
      while (walk_size--) {
        if (q.front() == nullptr) continue;
        TreeNode* cur_node = q.front();
        q.pop();

        TreeNode* child = nullptr;
        if (ss >> token && token != "null") {
          child = new TreeNode(stoi(token));
        }
        cur_node->left = child;
        child = nullptr;
        if (ss >> token && token != "null") {
          child = new TreeNode(stoi(token));
        }
        cur_node->right = child;

        if (cur_node->left != nullptr) q.push(cur_node->left);
        if (cur_node->right != nullptr) q.push(cur_node->right);
      }
    }
    return head;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

/**
 * Idea: do level-order traversal.
 */

/* Runtime
53 ms
Beats
89.36%
Memory
29.1 MB
Beats
84.8%
*/

