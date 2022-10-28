class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> window;
    vector<int> result;

    // loop the nums
    for (int i = 0; i < nums.size(); i++) {
      // to implement a structure that
      // cur_max = dq.front();
      // dq.front() gets popped out if it's out of the window
      
      // remove "expired" element
      while (window.size() >= k) {
        window.pop_front();
      }
      // when a larger num seen, push it at the end and pop out all smaller elements
      if (! window.empty() && nums[i] >= window.front()) {
        window.push_back(nums[i]);
        while (window.size() > 1) {
          window.pop_front();
        }
      } else {
      // when it's not larger than cur_max, we just push it at the end
        window.push_back(nums[i]);
      }
      
      // if i >= k - 1 (i >= 2 if k = 3: idx 0, 1, 2)
      // we can start getting the result at the front our dq
      if (i >= k - 1) {
        result.push_back(window.front());
      }
    }
    
    return result;
  }
};

/* wrong answer! need to store indices instead. */
