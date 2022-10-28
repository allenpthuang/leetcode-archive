class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int result = 0;
    
    unordered_map<int, int> par_sum_cnt_map_1;
    unordered_map<int, int> par_sum_cnt_map_2;
    
    for (const int& a : nums1) {
      for (const int& b : nums2) {
        par_sum_cnt_map_1[a + b]++;
      }
    }
    
    for (const int& c : nums3) {
      for (const int& d : nums4) {
        par_sum_cnt_map_2[c + d]++;
      }
    }
    
    for (const auto& left : par_sum_cnt_map_1) {
      for (const auto& right : par_sum_cnt_map_2) {
        if (left.first + right.first == 0) {
          result += left.second * right.second;
        }
      }
    }
    
    return result;
  }
};

/* Runtime: 554 ms, faster than 11.16% of C++ online submissions for 4Sum II.
 * Memory Usage: 27.5 MB, less than 15.75% of C++ online submissions for 4Sum II.
 */

