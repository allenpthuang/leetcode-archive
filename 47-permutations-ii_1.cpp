class Solution {
 private:
  void worker(vector<vector<int> >& result, vector<int>& cur_res,
              vector<int>& nums, vector<bool>& used) {
    if (cur_res.size() == nums.size()) {
      result.push_back(cur_res);
      return;
    }
    
    for (int i = 0; i < nums.size(); i++) {
      if (used[i]) continue;
      if (i > 0 && nums[i] == nums[i - 1] && ! used[i - 1]) continue;
      cur_res.push_back(nums[i]);
      used[i] = true;
      worker(result, cur_res, nums, used);
      used[i] = false;
      cur_res.pop_back();
    }
  }
 public:
  vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int> > result;
    vector<int> cur_res;
    vector<bool> used(nums.size(), false);
    sort(nums.begin(), nums.end());
    worker(result, cur_res, nums, used);
    
    return result;
  }
};

/* Runtime: 11 ms, faster than 62.83% of C++ online submissions for Permutations II.
 * Memory Usage: 8.5 MB, less than 80.24% of C++ online submissions for Permutations II.
 */

