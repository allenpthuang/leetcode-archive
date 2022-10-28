class Solution {
 public:
  bool canJump(vector<int>& nums) {
    vector<bool> reachable(nums.size(), false);
    reachable[0] = true;
    
    for (int i = 0; i < nums.size(); i++) {
      if (reachable[i]) {
        for (int j = i + 1; j <= nums[i] + i; j++) {
          if (j >= nums.size()) break;
          reachable[j] = true;
        }
      }
    }
    
    return reachable[nums.size() - 1];
  }
};

/* TLE */
