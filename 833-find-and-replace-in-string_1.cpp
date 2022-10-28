class Solution {
 public:
  string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
    unordered_map<int, int> m;
    for (int j = 0; j < indices.size(); j++) {
      m[indices[j]] = j;
    }
    
    string result = "";
    for (int i = 0; i < s.size(); i++) {
      if (m.count(i) == 0) {
        result += s[i];
      } else {
        if (sources[m[i]] == s.substr(i, sources[m[i]].size())) {
          result += targets[m[i]];
          i += sources[m[i]].size() - 1; // -1 to negate i++ of the for-loop
        } else {
          result += s[i];
        }
      }
    }
    
    return result;
  }
};

/* Runtime: 17 ms, faster than 6.39% of C++ online submissions for Find And Replace in String.
 * Memory Usage: 10.6 MB, less than 78.47% of C++ online submissions for Find And Replace in String.
 */

