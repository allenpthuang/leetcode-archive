class Solution {
 public:
  int numSquares(int n) {
    // dp[i]: the least number of num^2 that sum to i
    vector<int> dp(n + 1, INT_MAX - 1);
    
    // we only need sqrt(n) + 1
    const int N = sqrt(n) + 1;

    // dp[0]
    dp[0] = 0;
    
    // walk thru the squares ('items') first
    for (int i = 1; i <= N; i++) {
      for (int j = 0; j <= n; j++) {
        if (j - (i * i) >= 0) {
          dp[j] = min(dp[j], dp[j - (i * i)] + 1);
        }
      }
    }
    return dp[n];
  }
};

/* Runtime: 176 ms, faster than 51.22% of C++ online submissions for Perfect Squares.
 * Memory Usage: 9.1 MB, less than 44.13% of C++ online submissions for Perfect Squares.
 */

