class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> result(nums.size(), 0);
    vector<int> sorted;
    
    for (int i = nums.size() - 1; i >= 0; i--) {
      auto ins_it = lower_bound(sorted.begin(), sorted.end(), nums[i]);
      int d = distance(sorted.begin(), ins_it);
      result[i] = d;
      sorted.insert(sorted.begin() + d, nums[i]);
    }
    return result;
  }
};

/* TLE */

