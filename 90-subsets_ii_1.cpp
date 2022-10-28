class Solution {
 private:
  void worker(vector<vector<int> >& result, vector<int>& cur_res, vector<int>& nums,
              vector<bool>& used, int cur_idx = 0) {
    result.push_back(cur_res);
    if (cur_idx == nums.size()) return;
    
    for (int i = cur_idx; i < nums.size(); i++) {
      if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
        continue;
      }
      cur_res.push_back(nums[i]);
      used[i] = true;
      worker(result, cur_res, nums, used, i + 1);
      used[i] = false;
      cur_res.pop_back();
    }
  }

 public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > result;
    vector<int> cur_res;
    vector<bool> used(nums.size(), false);
    
    worker(result, cur_res, nums, used);
    
    return result;
  }
};

/* Runtime: 3 ms, faster than 80.82% of C++ online submissions for Subsets II.
 * Memory Usage: 7.6 MB, less than 73.38% of C++ online submissions for Subsets II.
 */

