class Solution {
 private:
  void dfs(vector<vector<pair<int, int> > >& graph,
           vector<unordered_set<int> >& neighbors,
           int orig_city, int cur_city, int rem_distance) {
    if (rem_distance < 0) {
        //|| neighbors[orig_city].find(cur_city) != neighbors[orig_city].end()) {
      return;
    }
    if (cur_city != orig_city) {
      neighbors[orig_city].insert(cur_city);
    }
    for (const auto& [dest, weight] : graph[cur_city]) {
      dfs(graph, neighbors, orig_city, dest, rem_distance - weight);
    }
  }

 public:
  int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<pair<int, int> > > graph(n);  // (from -> (to, weight))
    for (const auto& edge : edges) {
      graph[edge[0]].push_back({edge[1], edge[2]});
      graph[edge[1]].push_back({edge[0], edge[2]});
    }
    
    vector<unordered_set<int> > neighbors(n);  // (city -> visited_neighors)
    for (int i = 0; i < n; i++) {
      dfs(graph, neighbors, i, i, distanceThreshold);
    }
    
    int cur_least_num_neighbors = INT_MAX;
    int cur_ans = -1;
    for (int i = 0; i < n; i++) {
      // cout << i << ": " << neighbors[i].size() << endl;
      if (neighbors[i].size() <= cur_least_num_neighbors) {
        cur_least_num_neighbors = neighbors[i].size();
        cur_ans = i;
      }
    }
    return cur_ans;
  }
};

/* TLE */

