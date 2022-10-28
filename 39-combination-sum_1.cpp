class Solution {
 private:
  void worker(vector<vector<int> >& result, vector<int>& cur_res,
              vector<int>& candidates, int target,
              int cur_idx = 0, int cur_sum = 0) {
    if (cur_sum == target) {
      result.push_back(cur_res);
      return;
    } else if (cur_sum > target) {
      return;
    }
    
    for (int i = cur_idx; i < candidates.size(); i++) {
      cur_res.push_back(candidates[i]);
      worker(result, cur_res, candidates, target, i, cur_sum + candidates[i]);
      cur_res.pop_back();
    }
  }
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int> > result;
    vector<int> cur_res;
    
    worker(result, cur_res, candidates, target);
    
    return result;
  }
};

/* Runtime: 11 ms, faster than 63.55% of C++ online submissions for Combination Sum.
 * Memory Usage: 10.9 MB, less than 63.93% of C++ online submissions for Combination Sum.
 */

