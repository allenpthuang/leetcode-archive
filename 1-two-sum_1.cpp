class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          if (i != j) {
            return vector<int> {i, j};
          }
        }
      }
    }
    return vector<int> {-5566, -5566};
  }
};

/*
 * Runtime: 636 ms, faster than 8.68% of C++ online submissions for Two Sum.
Memory Usage: 10.2 MB, less than 65.82% of C++ online submissions for Two Sum.
*/

