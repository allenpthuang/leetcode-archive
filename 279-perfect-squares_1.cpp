class Solution {
 public:
  int numSquares(int n) {
    // dp[i]: the least number of num^2 that sum to i
    vector<int> dp(n + 1, INT_MAX - 1);
    
    // build the 'items' vector
    // since n <= 10^4, we can safely build just 1 to 100
    vector<int> squares(100);
    for (int i = 0; i < squares.size(); i++) {
      squares[i] = (i + 1) * (i + 1);
    }
    
    // dp[0]
    dp[0] = 0;
    
    // walk thru the squares ('items') first
    for (int i = 0; i < squares.size(); i++) {
      for (int j = 0; j <= n; j++) {
        if (j - squares[i] >= 0) {
          dp[j] = min(dp[j], dp[j - squares[i]] + 1);
        }
      }
    }
    return dp[n];
  }
};

/* Runtime: 344 ms, faster than 17.16% of C++ online submissions for Perfect Squares.
 * Memory Usage: 9.3 MB, less than 34.68% of C++ online submissions for Perfect Squares.
 */

