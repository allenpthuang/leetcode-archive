class Solution {
 private:
  void worker(vector<vector<int> >& result, vector<int> candidates,
              int k, vector<int> cur_res = vector<int>()) {
    if (k == 0) {
      sort(cur_res.begin(), cur_res.end());
      result.push_back(cur_res);
      return;
    }
    
    for (const auto& c : candidates) {
      cur_res.push_back(c);
      vector<int> new_candidates = candidates;
      new_candidates.erase(find(new_candidates.begin(), new_candidates.end(), c));
      worker(result, new_candidates, k - 1, cur_res);
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
    worker(result, candidates, k);
    set<vector<int> > s(result.begin(), result.end());
    vector<vector<int> > result_clean(s.begin(), s.end());
    return result_clean;
  }
};

/* TLE */
