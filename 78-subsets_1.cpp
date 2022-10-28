class Solution {
 private:
  void worker(vector<vector<int> >& result, vector<int>& cur_res, vector<int>& nums,
              int k, int cur_idx) {
    if (k == 0) {
      result.push_back(cur_res);
      return;
    }
    
    for (int i = cur_idx; i < nums.size(); i++) {
      cur_res.push_back(nums[i]);
      worker(result, cur_res, nums, k - 1, i + 1);
      cur_res.pop_back();
    }
  }
 public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int> > result;
    vector<int> cur_res;
    
    for (int k = 0; k <= nums.size(); k++) {
      cur_res.clear();
      worker(result, cur_res, nums, k, 0);
    }
    
    return result;
  }
};

/* Runtime: 0 ms, faster than 100.00% of C++ online submissions for Subsets.
 * Memory Usage: 6.9 MB, less than 95.76% of C++ online submissions for Subsets.
 */

