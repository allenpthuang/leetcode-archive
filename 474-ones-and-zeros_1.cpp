class Solution {
 public:
  void countZerosOnes(string& str, vector<int>& counter) {
    int counter_zeros = 0;
    int counter_ones = 0;
    for (const auto& c : str) {
      if (c == '0') {
        counter_zeros++;
      } else if (c == '1') {
        counter_ones++;
      }
    }
    counter[0] = counter_zeros;
    counter[1] = counter_ones;
  }
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int> > counters(strs.size(), vector<int>(2, 0));
    for (int i = 0; i < strs.size(); i++) {
      countZerosOnes(strs[i], counters[i]);
    }
    vector<vector<int> > dp(m + 1,
                            vector<int>(n + 1, 0));
    for (int i = 0; i < strs.size(); i++) {
      for (int j = m; j >= counters[i][0]; j--) {
        for (int k = n; k >= counters[i][1]; k--) {
          dp[j][k] = max(dp[j][k],
                         dp[j - counters[i][0]][k - counters[i][1]] + 1);
        }
      }
    }
    return dp[m][n];
  }
};

/*
 * Runtime: 631 ms, faster than 11.22% of C++ online submissions for Ones and Zeroes.
 * Memory Usage: 10 MB, less than 59.36% of C++ online submissions for Ones and Zeroes.
 */
