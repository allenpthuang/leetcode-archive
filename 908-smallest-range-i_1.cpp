class Solution {
 public:
  int smallestRangeI(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int diff = nums[nums.size() - 1] - nums[0];
    if (diff > k * 2) {
      return diff - k * 2; 
    } else {
      return 0;
    }
  }
};

/* Runtime: 24 ms, faster than 59.29% of C++ online submissions for Smallest Range I.
 * Memory Usage: 15.5 MB, less than 57.06% of C++ online submissions for Smallest Range I.
 */

