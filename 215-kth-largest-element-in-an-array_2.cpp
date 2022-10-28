class Solution {
 public:
  int findKthLargest(vector<int>& nums, int k) {
    map<int, int> m;
    for (const auto& num : nums) {
      m[num]++;
    }

    auto it = m.begin();
    int cur_k = nums.size();
    for (; it != m.end(); it++) {
      cur_k -= it->second;
      if (cur_k < k) {
        break;
      }
    }
    return it->first;
  }
};

/*Runtime: 33 ms, faster than 17.31% of C++ online submissions for Kth Largest Element in an Array.
 * Memory Usage: 12.3 MB, less than 8.30% of C++ online submissions for Kth Largest Element in an Array.
 */

