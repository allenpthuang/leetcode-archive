class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    bool seen_anomaly = false;
    if (nums.size() == 1) {
      return true;
    }
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < nums[i - 1]) {
        if (seen_anomaly) {
          return false;
        }
        seen_anomaly = true;
        if (i == 1 || nums[i - 2] <= nums[i]) {
          nums[i - 1] = nums[i];
        } else {
          nums[i] = nums[i - 1];
        }
      }
    }
    return true;
  }
};

/* Runtime: 80 ms, faster than 5.12% of C++ online submissions for Non-decreasing Array.
 * Memory Usage: 27.1 MB, less than 54.22% of C++ online submissions for Non-decreasing Array.
 */

