class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> rem;  // (rem, idx)
    for (int i = 0; i < nums.size(); i++) {
      if (rem.count(nums[i]) > 0) {
        return vector<int>{i, rem[nums[i]]};
      }
      rem[target - nums[i]] = i;
    }
    return vector<int>();
  }
};

/* Runtime: 9 ms, faster than 94.83% of C++ online submissions for Two Sum.
 * Memory Usage: 10.7 MB, less than 53.63% of C++ online submissions for Two Sum.
 */
