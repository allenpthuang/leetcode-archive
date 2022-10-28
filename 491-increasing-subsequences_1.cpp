class Solution {
 private:
  void worker(vector<vector<int> >& result, vector<int>& cur_res, vector<int>& nums,
              int cur_idx = 0) {
    if (cur_res.size() >= 2) {
      result.push_back(cur_res);
    }
    if (cur_idx == nums.size()) {
      return;
    }
    
    unordered_set<int> used;
    for (int i = cur_idx; i < nums.size(); i++) {
      if (used.count(nums[i]) != 0) {
        continue;
      }
      if (cur_res.size() == 0 || nums[i] >= cur_res[cur_res.size() - 1]) {
        cur_res.push_back(nums[i]);
        used.insert(nums[i]);
        worker(result, cur_res, nums, i + 1);
        cur_res.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<vector<int> > result;
    vector<int> cur_res;
    vector<bool> used(nums.size(), false);
    
    worker(result, cur_res, nums);
    
    return result;
  }
};

/* Runtime: 78 ms, faster than 75.51% of C++ online submissions for Increasing Subsequences.
 * Memory Usage: 21.9 MB, less than 90.63% of C++ online submissions for Increasing Subsequences.
 */

