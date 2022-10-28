class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for (const int& stone : stones) {
      sum += stone;
    }
    
    int target = sum / 2;
    
    vector<int> dp(target + 1, 0);
    for (int i = 0; i < stones.size(); i++) {
      for (int j = target; j >= stones[i]; j--) {
        dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }
    return (sum - dp[target]) - dp[target];
  }
};

/*
 * Runtime: 0 ms, faster than 100.00% of C++ online submissions for Last Stone Weight II.
Memory Usage: 8.4 MB, less than 48.06% of C++ online submissions for Last Stone Weight II.
*/

