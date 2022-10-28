class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    for (const auto& num : nums) {
      pq.push(num);
    }
    
    int cur_k = 0;
    while (cur_k < k - 1) {
      pq.pop();
      cur_k++;
    }
    return pq.top();
  }
};

/* Runtime: 8 ms, faster than 74.76% of C++ online submissions for Kth Largest Element in an Array.
 * Memory Usage: 10.3 MB, less than 12.97% of C++ online submissions for Kth Largest Element in an Array.
 */


