class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    // left pos: i
    // right pos: i + k - 1
    // end pos: i = nums.size() - k
    int cur_max = INT_MIN;
    // int lpos = 0;
    // int rpos = nums.size() - k;
    int rightmost_max_pos = 0;
    
    vector<int> result;
    
    for (int i = 0; i < k; i++) {
      if (nums[i] >= cur_max) {
        cur_max = nums[i];
        rightmost_max_pos = i;
      }
    }
    
    result.push_back(cur_max);
    
    for (int i = 1; i <= nums.size() - k; i++) {
      if (nums[i + k - 1] >= cur_max) {
        cur_max = nums[i + k - 1];
        rightmost_max_pos = i + k - 1;
      } else if (rightmost_max_pos < i) {
        cur_max = INT_MIN;
        for (int j = i; j < i + k; j++) {
          if (nums[j] >= cur_max) {
            cur_max = nums[j];
            rightmost_max_pos = j;
          }
        }
      }
      result.push_back(cur_max);
    }
    
    // return vector<int>(nums.begin() + lpos, nums.begin() + lpos + k);
    return result;
  }
};

/* TLE */
