class Solution {
 private:
  void worker(vector<vector<int> >& graph, vector<vector<int> >& paths, vector<int>& cur_path, int src, int dst) {
    if (src == dst) {
      paths.push_back(cur_path);
      return;
    }
    for (const auto& next_src : graph[src]) {
      cur_path.push_back(next_src);
      worker(graph, paths, cur_path, next_src, dst);
      cur_path.pop_back();
    }
  }
 public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<vector<int> > paths;
    vector<int> cur_path = {0};
    worker(graph, paths, cur_path, 0, graph.size() - 1);
    return paths;
  }
};

/* Runtime: 28 ms, faster than 48.61% of C++ online submissions for All Paths From Source to Target.
 * Memory Usage: 10.6 MB, less than 81.92% of C++ online submissions for All Paths From Source to Target.
 */

