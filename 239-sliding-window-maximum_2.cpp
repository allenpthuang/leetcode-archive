class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    multiset<int> window;
    
    for (int i = 0; i < k; i++) {
      window.insert(nums[i]);
    }
    result.push_back(*window.rbegin());
    
    int left = nums[0];
    for (int i = 1; i <= nums.size() - k; i++) {
      auto pos = window.find(left);
      window.erase(pos);
      window.insert(nums[i + k - 1]);
      left = nums[i];
      result.push_back(*window.rbegin());
    }
    return result;
  }
};

/* Runtime: 616 ms, faster than 8.27% of C++ online submissions for Sliding Window Maximum.
 * Memory Usage: 206.8 MB, less than 9.50% of C++ online submissions for Sliding Window Maximum.
 */

