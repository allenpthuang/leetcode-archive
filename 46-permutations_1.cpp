class Solution {
 public:
  vector<vector<int>> permute(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > result;
    
    do {
      result.push_back(nums);
    } while (next_permutation(nums.begin(), nums.end()));
    
    return result;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Permutations.
 * Memory Usage: 7.6 MB, less than 91.90% of C++ online submissions for Permutations.
 */

