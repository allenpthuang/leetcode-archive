class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    // (a + b) + (c + d) = target = 0
    // we log down the freq of the values of (a + b) & (c + d)
    int result = 0; // will not overflow as input n <= 200
    
    unordered_map<int, int> left; // ((a + b), freq)
    unordered_map<int, int> right; // ((c + d), freq)
    
    // all combos for a & b
    for (const auto& a : nums1) {
      for (const auto& b : nums2) {
        left[a + b]++;
      }
    }
    
    // all combos for c & d
    for (const auto& c : nums3) {
      for (const auto& d : nums4) {
        right[c + d]++;
      }
    }
    
    // try all combos for (a + b) + (c + d) == 0
    for (const auto& l : left) {
      for (const auto& r : right) {
        if (l.first + r.first == 0) {
          result += l.second * r.second;
        }
      }
    }
    
    return result;
  }
};

/* Runtime: 777 ms, faster than 6.78% of C++ online submissions for 4Sum II.
 * Memory Usage: 27.7 MB, less than 13.96% of C++ online submissions for 4Sum II.
 */


