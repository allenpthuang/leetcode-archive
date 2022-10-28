class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<pair<int, int> > window;
    vector<int> result;

    // loop the nums
    for (int i = 0; i < nums.size(); i++) {
      // to implement a structure that
      // cur_max = dq.front();
      // dq.front() gets popped out if it's out of the window
      // to do this, we need to store the indices
      
      // remove "expired" element
      while (! window.empty() && window.front().first <= i - k) {
        window.pop_front();
      }
      
      // if the new element is larger than the back of the window, pop the back
      // since it's not possible to be a max
      while (! window.empty() && nums[i] >= window.back().second) {
        window.pop_back();
      }
      window.push_back(pair<int, int>{i, nums[i]});
      
      // if i >= k - 1 (i >= 2 if k = 3: idx 0, 1, 2)
      // we can start getting the result at the front our dq
      if (i >= k - 1) {
        result.push_back(window.front().second);
      }
    }
    
    return result;
  }
};

/* Runtime: 319 ms, faster than 91.18% of C++ online submissions for Sliding Window Maximum.
 * Memory Usage: 137 MB, less than 35.65% of C++ online submissions for Sliding Window Maximum.
 */

