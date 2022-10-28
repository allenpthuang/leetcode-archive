class Solution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
    }
    int avg;
    if (sum % 2 != 0) {
      return false;
    } else {
      avg = sum / 2;
    }
    
    vector<int> dp(avg + 1, 0);
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = avg; j >= nums[i]; --j) {
        dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
      }
    }
    if (dp[avg] == avg) {
      return true;
    } else {
      return false;
    }
  }
};

/*
 * Runtime: 204 ms, faster than 39.80% of C++ online submissions for Partition Equal Subset Sum.
Memory Usage: 9.9 MB, less than 72.57% of C++ online submissions for Partition Equal Subset Sum.
*/

