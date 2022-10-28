class Solution {
 private:
  void dfs(unordered_map<string,
                         priority_queue<string,
                                        vector<string>,
                                        greater<string> > >& dests,
           vector<string>& path, string departure) {
    while (dests[departure].size() > 0) {
      string next_dep = dests[departure].top();
      dests[departure].pop();
      dfs(dests, path, next_dep);
    }
    path.push_back(departure);
  }

 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, priority_queue<string, vector<string>, greater<string> > > dests;
    for (const auto& t : tickets) {
      dests[t[0]].push(t[1]);
    }
    
    vector<string> path;
    dfs(dests, path, "JFK");
    reverse(path.begin(), path.end());
    return path;
  }
};

/* Runtime: 45 ms, faster than 32.34% of C++ online submissions for Reconstruct Itinerary.
 * Memory Usage: 14.1 MB, less than 84.71% of C++ online submissions for Reconstruct Itinerary.
 */

