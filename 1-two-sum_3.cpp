class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
      int counterpart = target - nums[i];
      if (seen.find(counterpart) != seen.end()) {
        int idx_counterpart = seen[counterpart];
        return vector<int> {i, idx_counterpart};
      } else {
        seen[nums[i]] = i;
      }
    }
    return vector<int> {-5566, -5566};
  }
};

/* Runtime: 10 ms, faster than 89.32% of C++ online submissions for Two Sum.
 * Memory Usage: 10.7 MB, less than 51.79% of C++ online submissions for Two Sum.
 */

