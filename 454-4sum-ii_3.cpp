class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    // (a + b) + (c + d) = target = 0
    // we log down the freq of the values of (a + b) & (c + d)
    int result = 0; // will not overflow as input n <= 200
    
    unordered_map<int, int> left; // ((a + b), freq)
    
    // all combos for a & b
    for (const auto& a : nums1) {
      for (const auto& b : nums2) {
        left[a + b]++;
      }
    }
    
    // all combos for c & d, and we detect (a + b) + (c + d) == 0 along the way
    for (const auto& c : nums3) {
      for (const auto& d : nums4) {
        if (left.count(0 - (c + d)) > 0) {
          result += left[0 -(c + d)];
        }
      }
    }
    
    return result;
  }
};

/* Runtime: 391 ms, faster than 52.98% of C++ online submissions for 4Sum II.
 * Memory Usage: 24.2 MB, less than 95.81% of C++ online submissions for 4Sum II.
 */

