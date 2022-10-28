class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> st1(nums1.begin(), nums1.end());
    unordered_set<int> st2(nums2.begin(), nums2.end());
    
    vector<int> result;
    if (st1.size() > st2.size()) {
      for (const auto& e : st2) {
        if (st1.count(e) > 0) {
          result.push_back(e);
        }
      }
    } else {
      for (const auto& e : st1) {
        if (st2.count(e) > 0) {
          result.push_back(e);
        }
      }
    }
    
    return result;
  }
};

/* Runtime: 13 ms, faster than 36.48% of C++ online submissions for Intersection of Two Arrays.
 * Memory Usage: 10.8 MB, less than 11.25% of C++ online submissions for Intersection of Two Arrays.
 */

