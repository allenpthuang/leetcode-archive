class Solution {
 public:
  bool checkPossibility(vector<int>& nums) {
    bool seen_anomaly = false;
    if (nums.size() == 1) {
      return true;
    }
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] - nums[i - 1] < 0) {
        if (seen_anomaly) {
          return false;
        }
        seen_anomaly = true;
      }
    }
    return true;
  }
};

/* wrong answer */

