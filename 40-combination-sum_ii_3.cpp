class Solution {
 private:
  void worker(vector<vector<int> >& result, vector<int>& cur_res,
              vector<int>& candidates, int target, vector<bool>& used,
              int cur_idx = 0, int cur_sum = 0) {
    if (cur_sum == target) {
      result.push_back(cur_res);
      return;
    } else if (cur_sum > target) {
      return;
    }
    
    for (int i = cur_idx; i < candidates.size() && cur_sum + candidates[i] <= target; i++) {
      if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
        continue;
      }
      cur_res.push_back(candidates[i]);
      used[i] = true;
      worker(result, cur_res, candidates, target, used, i + 1, cur_sum + candidates[i]);
      used[i] = false;
      cur_res.pop_back();
    }
  }
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int> > result;
    vector<int> cur_res;
    vector<bool> used(candidates.size(), false);
    
    sort(candidates.begin(), candidates.end());
    worker(result, cur_res, candidates, target, used);
    return result;
  }
};

/* Runtime: 7 ms, faster than 73.34% of C++ online submissions for Combination Sum II.
 * Memory Usage: 10.6 MB, less than 87.71% of C++ online submissions for Combination Sum II.
 */

