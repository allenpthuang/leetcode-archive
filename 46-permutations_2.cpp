class Solution {
 private:
  void worker(vector<vector<int> >& result, vector<int>& cur_res, vector<int>& nums,
              vector<bool>& used) {
    if (cur_res.size() == nums.size()) {
      result.push_back(cur_res);
      return;
    }
    
    unordered_set<int> used_idx;
    for (int i = 0; i < nums.size(); i++) {
      if (! used[i]) {
        cur_res.push_back(nums[i]);
        used[i] = true;
        worker(result, cur_res, nums, used);
        used[i] = false;
        cur_res.pop_back();
      }
    }
  }

 public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > result;
    vector<int> cur_res;
    vector<bool> used(nums.size(), false);
    worker(result, cur_res, nums, used);
    return result;
  }
};

/* Runtime: 5 ms, faster than 46.54% of C++ online submissions for Permutations.
 * Memory Usage: 7.7 MB, less than 55.84% of C++ online submissions for Permutations.
 */

