class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen;
    for (int i = 0; i < nums.size(); i++) {
      if (seen.count(target - nums[i]) > 0) {
        return vector<int> {seen[target - nums[i]], i};
      } else {
        seen[nums[i]] = i;
      }
    }
    return vector<int> {-5566, -5566};
  }
};

/*
 * Runtime: 12 ms, faster than 77.78% of C++ online submissions for Two Sum.
Memory Usage: 10.7 MB, less than 57.67% of C++ online submissions for Two Sum.
*/

