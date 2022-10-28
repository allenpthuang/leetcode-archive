class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    
    int left = 0;
    int right = 0;
    while (right < nums.size()) {
      priority_queue<int> pq;
      right = left + k;
      for (int i = left; i < right; i++) {
        pq.push(nums[i]);
      }
      result.push_back(pq.top());
      left++;
    }
    return result;
  }
};

/* TLE */

