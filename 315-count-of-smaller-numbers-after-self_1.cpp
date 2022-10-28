class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    vector<int> counts(nums.size(), 0);
    
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] > nums[j]) counts[i]++;
      }
    }
    return counts;
  }
};

/* TLE */

