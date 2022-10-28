class Solution {
 public:
  string destCity(vector<vector<string>>& paths) {
    unordered_map<string, int> m;
    // init.
    for (const auto& p : paths) {
      m[p[0]]++;
      if (m.find(p[1]) == m.end()) {
        m[p[1]] = 0;
      }
    }
    for (const auto& c : m) {
      if (c.second == 0) {
        return c.first;
      }
    }
    return "";
  }
};

/* Runtime: 8 ms, faster than 97.80% of C++ online submissions for Destination City.
 * Memory Usage: 10.8 MB, less than 72.08% of C++ online submissions for Destination City.
 */

