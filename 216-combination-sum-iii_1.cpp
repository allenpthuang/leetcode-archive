class Solution {
 private:
  void worker(set<vector<int> >& result, vector<int> cur_res, vector<int> candidates,
              int k, int rem) {
    if (k == 0 && rem == 0) {
      sort(cur_res.begin(), cur_res.end());
      result.insert(cur_res);
      return;
    }
    if (rem > 0) {
      for (const auto& c : candidates) {
        cur_res.push_back(c);
        vector<int> new_candidates = candidates;
        new_candidates.erase(find(new_candidates.begin(), new_candidates.end(), c));
        worker(result, cur_res, new_candidates, k - 1, rem - c);
        cur_res.pop_back();
      }
    } else {
      return;
    }
  }
 public:
  vector<vector<int>> combinationSum3(int k, int n) {
    set<vector<int> > result;
    vector<int> cur_res;
    vector<int> candidates;
    for (int i = 1; i <= 9; i++) candidates.push_back(i);
    worker(result, cur_res, candidates, k, n);
    return vector<vector<int> > (result.begin(), result.end());
  }
};

/* TLE */

