class Solution {
 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    vector<vector<int> > graph(n, vector<int>());
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    for (const auto& tos : graph) {
      if (tos.empty()) return false;
    }
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    while (! q.empty()) {
      auto walk_size = q.size();
      while (walk_size--) {
        int cur_parent = q.front();
        q.pop();
        if (visited[cur_parent] == true) return false;
        visited[cur_parent] = true;
        for (const auto& child : graph[cur_parent]) {
          if (visited[child] == true && child != cur_parent) return false;
          q.push(child);
        }
      }
    }
    return true;
  }
};

/** Idea:
 * Construct the graph from `edges` first by adding from and to.
 * Then walk the graph to see if we're visiting some nodes we've seen.
 */


/* wrong answer */

