/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
 public:
  Node* cloneGraph(Node* node) {
    if (node == nullptr) return nullptr;
    unordered_map<int, Node*> visited;
    unordered_map<int, Node*> cloned;
    queue<Node*> q;
    // visited[node->val] = node;
    q.push(node);
    while (! q.empty()) {
      Node* cur_node = q.front();
      q.pop();
      if (visited.find(cur_node->val) != visited.end()) {
        continue;
      }
      visited[cur_node->val] = cur_node;

      // look up or add to cloned
      Node* cloned_node = nullptr;
      if (cloned.find(cur_node->val) == cloned.end()) {
        cloned_node = new Node(cur_node->val);
        cloned[cloned_node->val] = cloned_node;
      } else {
        cloned_node = cloned[cur_node->val];
      }

      for (const auto& neighbor : cur_node->neighbors) {
        if (visited.find(neighbor->val) == visited.end()) {
          q.push(neighbor);
        }

        // make neighbor nodes (ok to leave their list empty)
        if (cloned.find(neighbor->val) == cloned.end()) {
          Node* cloned_neighbor = new Node(neighbor->val);
          cloned[cloned_neighbor->val] = cloned_neighbor;
          cloned_node->neighbors.push_back(cloned_neighbor);
        } else {
          cloned_node->neighbors.push_back(cloned[neighbor->val]);
        }
      }
    }

    return cloned[1];

    // Node* result = nullptr;
    // auto num_of_nodes = visited.size();
    // vector<Node*> cloned(num_of_nodes + 1, nullptr);
    // for (auto i = 1u; i <= num_of_nodes; i++) {

    // }
  }
};

/**
 * Idea: make all the nodes and store them in a vector,
 * and then make connections for every of them.
 * It is actually more complicated: only the first node
 * is given! Need to traverse the graph.
 */

// Note: looking at it now, `visited` is not necessary!

/* Runtime
7 ms
Beats
84.16%
Memory
8.6 MB
Beats
72.85%
*/

