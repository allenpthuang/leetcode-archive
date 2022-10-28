class Solution {
 public:
  int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() == 1) {
      return 1;
    }
    
    bool cur_positive = true;
    if (nums[1] >= nums[0]) {
      cur_positive = true;
    } else {
      cur_positive = false;
    }

    int result = nums.size();
    for (int i = 1; i < nums.size(); i++) {
      bool loop_positive = nums[i] >= nums[i-1];
      if (loop_positive == cur_positive || nums[i] == nums[i-1]) {
        result--;
      } else {
        cur_positive = loop_positive;
      }
    }
    
    return result + 1;
  }
};

/* wrong answer */

