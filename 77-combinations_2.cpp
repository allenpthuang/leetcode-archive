class Solution {
 private:
  void worker(vector<vector<int> >& result, vector<int>& candidates,
              int k, int cur_idx, vector<int> cur_res = vector<int>()) {
    if (k == 0) {
      result.push_back(cur_res);
      return;
    }
    
    for (int i = cur_idx; i < candidates.size(); i++) {
      cur_res.push_back(candidates[i]);
      worker(result, candidates, k - 1, i + 1, cur_res);
      cur_res.pop_back();
    }
    
  }
 public:
  vector<vector<int>> combine(int n, int k) {
    vector<int> candidates;
    for (int i = 1; i <= n; i++) {
      candidates.push_back(i);
    }
    vector<vector<int> > result;
    worker(result, candidates, k, 0);
 
    return result;
  }
};

/* Runtime: 595 ms, faster than 15.25% of C++ online submissions for Combinations.
 * Memory Usage: 164.3 MB, less than 12.98% of C++ online submissions for Combinations.
 */

