class Solution {
 public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    if (s.size() == 0) return 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    
    int g_idx = 0;
    
    for (int i = 0; i < s.size(); i++) {
      if (g_idx >= g.size()) break;
      if (s[i] >= g[g_idx]) {
        g_idx++;
      }
    }
    return g_idx;
  }
};

/* Runtime: 51 ms, faster than 25.93% of C++ online submissions for Assign Cookies.
 * Memory Usage: 17.5 MB, less than 33.46% of C++ online submissions for Assign Cookies.
 */

