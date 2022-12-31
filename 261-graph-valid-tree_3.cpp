class Solution {
 private:
  bool dfs(int root, int parent, vector<vector<int> >& graph,
           vector<bool>& visited) {
    // base case
    if (graph[root].size() == 1 && graph[root][0] == parent
        && visited[root] == false) {
      visited[root] = true;
      return true;
    }

    // visited before, has a loop
    if (visited[root] == true) return false;

    // mark visited
    visited[root] = true;

    // visit children
    for (const auto& child : graph[root]) {
      if (child == parent) continue;
      if (dfs(child, root, graph, visited) == false) return false;
    }
    return true;
  }

 public:
  bool validTree(int n, vector<vector<int>>& edges) {
    vector<vector<int> > graph(n, vector<int>());
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    if (dfs(0, -1, graph, visited) == false) return false;

    // if we did not reach every node in one go, it is not a valid tree.
    for (const auto& visit : visited) {
      if (visit == false) return false;
    }
    return true;
  }
};

/** Idea:
 * Construct the graph from `edges` first by adding from and to.
 * Then walk the graph to see if we're visiting some nodes we've seen.
 */

/* Runtime
19 ms
Beats
86.64%
Memory
14 MB
Beats
34%
*/

