class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') {
      return 0;
    }
    
    vector<int> dp(s.size() + 1, 0);
    dp[s.size()] = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] == '0') {
        dp[i] = 0;
      } else {
        dp[i] = dp[i + 1];
      }
        
      if (i + 1 < s.size()) {
        if (s[i] == '1') {
          dp[i] += dp[i + 2];
        } else if (s[i] == '2' && s[i + 1] <= '6') {
          dp[i] += dp[i + 2];
        }
      }
    }
    return dp[0];
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode Ways.
 * Memory Usage: 6.3 MB, less than 26.05% of C++ online submissions for Decode Ways.
 */

