class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    vector<int> result;
    for (const int& x : nums) {
      if (result.size() == 0 || result.back() < x) {
        result.push_back(x);
      } else {
        auto it = lower_bound(result.begin(), result.end(), x);
        *it = x;
      }
    }
    return result.size();
  }
};

/* Runtime: 11 ms, faster than 86.74% of C++ online submissions for Longest Increasing Subsequence.
 * Memory Usage: 10.5 MB, less than 64.53% of C++ online submissions for Longest Increasing Subsequence.
 */

