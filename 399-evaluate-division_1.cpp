class Solution {
 private:
  double worker(unordered_map<string, vector<pair<string, double> > >& table,
                unordered_set<string> seen, string cur_stop, string target, double cur_product) {
    if (seen.count(cur_stop) > 0) {
      return -1.0;
    }
    seen.insert(cur_stop);
    if (table[cur_stop].size() == 0) {
      return -1.0;
    }
    if (cur_stop == target) {
      return cur_product;
    }
    for (const auto& p : table[cur_stop]) {
      double result = worker(table, seen, p.first, target, cur_product * p.second);
      if (result != -1.0) {
        return result;
      }
    }
    return -1.0;
  }

 public:
  vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    // build the dict
    unordered_map<string, vector<pair<string, double> > > table;
    for (int i = 0; i < equations.size(); i++) {
      table[equations[i][0]].push_back(pair<string, double>{equations[i][1], values[i]});
      table[equations[i][1]].push_back(pair<string, double>{equations[i][0], 1.0 / values[i]});
    }
    
    vector<double> result;
    for (const auto& q : queries) {
      unordered_set<string> seen;
      double res = worker(table, seen, q[0], q[1], 1.0);
      result.push_back(res);
    }
    
    return result;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Evaluate Division.
 * Memory Usage: 8.7 MB, less than 13.39% of C++ online submissions for Evaluate Division
 */

