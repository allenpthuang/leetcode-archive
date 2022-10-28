class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> indices;
    vector<int> result;
    
    for (int i = 0; i < nums.size(); i++) {
      while (! indices.empty() && indices.front() < i - k + 1) {
        indices.pop_front();
      }
      
      while (! indices.empty() && nums[indices.back()] < nums[i]) {
        indices.pop_back();
      }
      
      indices.push_back(i);
      if (i >= k - 1) {
        result.push_back(nums[indices.front()]);
      }
    }
    
    return result;
  }
};

/* Runtime: 373 ms, faster than 28.50% of C++ online submissions for Sliding Window Maximum.
 * Memory Usage: 131.8 MB, less than 87.53% of C++ online submissions for Sliding Window Maximum.
 */


