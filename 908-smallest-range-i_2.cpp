class Solution {
 public:
  int smallestRangeI(vector<int>& nums, int k) {
    int maximum = INT_MIN;
    int minimum = INT_MAX;
    for (const auto& n : nums) {
      maximum = max(maximum, n);
      minimum = min(minimum, n);
    }
    int diff = maximum - minimum;
    if (diff > 2 * k) {
      return diff - 2 * k;
    } else {
      return 0;
    }
  }
};

/* Runtime: 15 ms, faster than 92.87% of C++ online submissions for Smallest Range I.
 * Memory Usage: 15.2 MB, less than 99.70% of C++ online submissions for Smallest Range I.
 */

