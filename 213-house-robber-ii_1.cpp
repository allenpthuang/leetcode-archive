class Solution {
 public:
  int rob_helper(vector<int>& slice) {
    // dp[i]
    vector<int> dp(slice.size(), 0);
    
    // dp[0]
    if (slice.size() == 0) return 0;
    if (slice.size() == 1) return slice[0];
    dp[0] = slice[0];
    dp[1] = max(slice[0], slice[1]);
    
    // walk thru
    for (int i = 2; i < slice.size(); i++) {
      dp[i] = max(dp[i - 1], dp[i - 2] + slice[i]);
    }
    return dp[slice.size() - 1];
  }

  int rob(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    if (nums.size() == 1) return nums[0];

    int result;
    vector<int> slice_1(nums.begin(), nums.end() - 1);
    vector<int> slice_2(nums.begin() + 1, nums.end());
    result = max(rob_helper(slice_1), rob_helper(slice_2));
    return result;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for House Robber II.
 * Memory Usage: 8 MB, less than 13.15% of C++ online submissions for House Robber II.
 */


