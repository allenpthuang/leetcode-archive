class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> word_set(wordDict.begin(), wordDict.end());
    vector<bool> dp(s.length() + 1, false);
    
    dp[0] = true;
    
    for (int i = 1; i <= s.length(); i++) {
      for (int j = 0; j < i; j++) {
        string tmp_str = s.substr(j, i - j);
        if (dp[j] && (word_set.find(tmp_str) != word_set.end())) {
          dp[i] = true;
        }
      }
    }
    
    return dp[s.length()];
  }
};

/* Runtime: 20 ms, faster than 37.57% of C++ online submissions for Word Break.
 * Memory Usage: 14.7 MB, less than 23.14% of C++ online submissions for Word Break.
 */

