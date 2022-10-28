class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string> > gp;
    unordered_map<string, vector<string> > m;
    for (const auto& s : strs) {
      string tmp = s;
      sort(tmp.begin(), tmp.end());
      m[tmp].push_back(s);
    }
    for (const auto& e : m) {
      gp.push_back(e.second);
    }
    return gp;
  }
};

/* Runtime: 32 ms, faster than 91.75% of C++ online submissions for Group Anagrams.
 * Memory Usage: 19.6 MB, less than 80.88% of C++ online submissions for Group Anagrams.
 */
