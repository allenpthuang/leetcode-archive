class Solution {
 public:
  vector<vector<int>> palindromePairs(vector<string>& words) {
    vector<vector<int> > results;
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        if (i == j) continue;
        string candidate = words[i] + words[j];
        bool found = true;
        for (int k = 0; k < candidate.size(); k++) {
          if (candidate[k] != candidate[candidate.size() - k - 1]) {
            found = false;
            break;
          }
        }
        if (found) {
          results.push_back({i, j});
        }
      }
    }
    return results;
  }
};

/* brute-force, TLE */

