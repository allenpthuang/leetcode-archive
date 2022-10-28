class Solution {
 private:
  void worker(vector<vector<int> >& result, vector<int>& cur_res,
              vector<int>& candidates, int target, int cur_idx, int cur_sum) {
    if (cur_sum == target) {
      result.push_back(cur_res);
      return;
    } else if (cur_sum > target) {
      return;
    }
    
    for (int i = cur_idx; i < candidates.size(); i++) {
      cur_res.push_back(candidates[i]);
      worker(result, cur_res, candidates, target, i + 1, cur_sum + candidates[i]);
      cur_res.pop_back();
    }
  }
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int> > result;
    vector<int> cur_res;
    
    sort(candidates.begin(), candidates.end());
    worker(result, cur_res, candidates, target, 0, 0);
    set<vector<int> > st(result.begin(), result.end());
    vector<vector<int> > result_clean(st.begin(), st.end());
    return result_clean;
  }
};

/* TLE */

