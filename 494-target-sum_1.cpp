class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    // a vector to store results from each iteration thru nums
    // the results are stored as a hash table
    // key: sum, value: count.
    vector<unordered_map<int, int> > sums(nums.size() + 1);
    // there's one way to come from nothing
    sums[0][0] = 1;
    for (int i = 0; i < nums.size(); i++) {
      // go thru the hash map to update the next hash map (at i+1-th)
      for (const auto& sum : sums[i]) {
        int cur_sum = sum.first;
        int cur_count = sum.second;
        sums[i + 1][cur_sum + nums[i]] += cur_count;
        sums[i + 1][cur_sum - nums[i]] += cur_count;
      }
    }
    return sums[nums.size()][target];
  }
};

/*
 * Runtime: 216 ms, faster than 45.03% of C++ online submissions for Target Sum.
Memory Usage: 47.3 MB, less than 19.47% of C++ online submissions for Target Sum.
*/

